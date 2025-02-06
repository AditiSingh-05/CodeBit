## Screen and ViewModel
---

Context is an interface in Android that provides access to application-specific resources, system services, and app-level operations like launching activities or showing toasts.

___insertedVariable__
(Private, Mutable)
This is a private MutableStateFlow<DataType> inside ViewModel.
Holds the user input temporarily before exposing it to the UI.
It can be modified inside ViewModel.
Why Use _insertedVariable?
The UI shouldn't modify the ViewModel's state directly.
Keeping it private ensures that only ViewModel can modify it.
It follows the principle of encapsulation.

__insertedVariable__
This is a read-only StateFlow<DataType> exposed from the ViewModel to the UI.
The UI observes this variable, but cannot modify it.
Why Use insertedVariable?
The UI needs real-time updates when the user types.
Instead of modifying _insertedVariable directly, the UI collects its state.

__userVariable__
This fetches a stored value from UserRepository using stateIn().
Immutable : Cannot be modified inside ViewModel.
Why Use userVariable?
The app needs to retrieve stored user data (e.g., username, preferences).
Keeps the UI synchronized with the database.

__variable__
These variables store the current value of the text fields in the UI.
When the user types in a text field, viewModel.insertedEmail updates, and so does email.
UI automatically re-renders when the values change.

__Principle of Encapsulation (OOP Concept)__
Encapsulation is the concept of hiding internal details of an object and only exposing necessary functionalities through controlled access.

Key Idea:
🔹 Restrict direct access to object data.
🔹 Expose only necessary parts via getter/setter methods.
🔴 Problem: No restrictions—any part of the code can change information without validation.


__ScreenName.kt__

```kotlin
fun ScreenName(navController : NavController,viewModel:ScreenNameViewModel = hilt){
        val context = LocalContext.current

        val variable by viewModel.insertedvariable.collectAsState()

        val variable by viewModel.uservariable.collectAsState()

        TextField(
                value = variable,
                onValueChange = { viewModel.onInsertedVariableChange(it) }   //Function defined in ScreenNameViewModel
        )    
}

```

__ScreenNameViewmodel__

```kotlin

@HiltViewModel
class LoginScreenViewModel @Inject constructor(private val userDataRepository: UserDataRepository) : ViewModel(){

    private val _insertedvariable = MutableStateFlow<DataType>("")
    val insertedvariable: StateFlow<DataType> = _insertedvariable

    fun onInsertedVariableChange(variable: DataType){
        _insertedVariable.value = variable
    }

    val uservariable = userDataRepository.getUserVariable().stateIn(
        scope = viewModelScope,
        started = SharingStarted.WhileSubscribed(3000),
        initialValue = ""  //flow vs state flow
    )


}

```

__UserRepository__

```kotlin

@Singleton
class UserDataRepository @Inject constructor(private val userDataStore: UserDataStore) {
```
@Singleton → Ensures a single instance exists in the app.
@Inject constructor(...) → Uses Hilt to inject UserDataStore.

```kotlin
    fun getUserVariable(): Flow<DataType> {
        return userDataStore.userVariable
    }//repository to viewmodel.....vm will call this function
```
Retrieves userVariable as a Flow (automatically updates UI when changed).
Called by: ViewModel.

```kotlin
    //Age change
    fun getUserAge(): Flow<String?> {
        return userDataStore.userAge.map {
            it?.toString()
        }
    }

```
fun getUserAge(): Flow<String?> {
    return userDataStore.userAge.map {
        it?.toString()
    }
}

```kotlin

    suspend fun setUserAge(age: String){
        userDataStore.setUserAge(age.toIntOrNull()?: 0)
    }
```
Converts String → Int (0 if invalid).
Saves the value in DataStore.
Suspend function (runs in background).

```kotlin

    suspend fun setUserVariable(variable: DataType) {
        userDataStore.setUserVariable(variable)
    }  //datastore to repository  
}
```
Updates userVariable in DataStore.
Ensures asynchronous operation using coroutines.

__UserDataStore__

```kotlin

@Singleton
class UserDataStore @Inject constructor(@ApplicationContext private val context: Context) {

```
@Singleton → Ensures only one instance of UserDataStore is created.
@Inject constructor(...) → Uses Hilt dependency injection.
@ApplicationContext → Injects the app-level context to access DataStore.

```kotlin
    private val datastore = context.userDataStore
    private val userVariableKey = stringPreferencesKey("user_variable")
    private val userAgeKey = intPreferencesKey("user_age")
```

datastore → Instance of DataStore that stores key-value pairs.
userVariableKey → Key for storing userVariable as a String.
userAgeKey → Key for storing user's age as an Int.
```kotlin

    val userVariable: Flow<DataType?> =
        datastore.data.catch {
            emit(emptyPreferences())  //access
        }.map { preferences ->
            preferences[userVariableKey]
        }//device to datastore get value

```
```kotlin
Device → DataStore → Repository → ViewModel
Fetches userVariable as a Flow (reactive data stream).
Handles exceptions (catch { emit(emptyPreferences()) }).
Maps stored value using userVariableKey.
```

```kotlin
    val userAge: Flow<Int?> =
        datastore.data.catch{
            emit(emptyPreferences())
        }.map{preferences ->
            preferences[userAgeKey]
        }
```
Retrieves userAge as a Flow<Int?>.
Handles errors by emitting empty preferences.
```kotlin

    suspend fun setUserVariable(variable : DataType){
        datastore.edit{
                preferences ->
            preferences[userVariableKey] = variable
        }

    }//user entered data to datastore set value
```
Stores userVariable persistently in DataStore.
Uses suspend fun → Runs in background thread to avoid UI lag.

```kotlin

    suspend fun setUserAge(age : Int){
        datastore.edit{
                preferences ->
            preferences[userAgeKey] = age
        }
    }

}
```
Saves userAge to DataStore asynchronously.


