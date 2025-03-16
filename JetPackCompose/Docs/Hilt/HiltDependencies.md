# Dependency Injection in Android

__What is Dependency Injection?__

Lets say we  you  have a car, now every car needs engine to run.

_Without dependency injecton_
The Car is responsible fr creating its own engine-

```kotlin

class Engine {
    fun start() {
        println("Engine started")
    }
}

class Car {
    private val engine = Engine()  // Car creates its own Engine

    fun drive() {
        engine.start()
        println("Car is driving")
    }
}

fun main() {
    val car = Car()  // Creating Car
    car.drive()  // Starting the Car
}
```

Instead of getting the Engine from outside, it creates its own Engine inside the class (private val engine = Engine()).

Issues?
Tightly Coupled: The Car is permanently tied to a specific Engine. If we want to change the Engine (e.g., replace it with an ElectricEngine), we need to modify the Car class.
Hard to Test: We cannot easily replace the Engine with a fake version for testing.
Less Flexible: If we have different types of Engines, changing them becomes difficult.

_With Dependency Injection_
Instead of creating the Engine inside the Car, we pass it as a parameter when creating a Car.

```kotlin

class Engine {
    fun start() {
        println("Engine started")
    }
}

class Car(private val engine: Engine) {  // Engine is provided from outside

    fun drive() {
        engine.start()
        println("Car is driving")
    }
}

fun main() {
    val engine = Engine()  // Creating Engine first
    val car = Car(engine)  // Passing Engine to Car
    car.drive()  // Starting the Car
}

```
The Car does not create the Engine itself. Instead, it gets the Engine from outside. When we create a Car, we pass an Engine (val car = Car(engine)).
More Flexibility: We can provide different Engines without changing the Car class.


```kotlin

class DieselEngine {
    fun start() {
        println("Diesel Engine started")
    }
}

class ElectricEngine {
    fun start() {
        println("Electric Engine started")
    }
}

class Car(private val engine: Any) {  // Can accept any Engine type

    fun drive() {
        when (engine) {
            is DieselEngine -> engine.start()
            is ElectricEngine -> engine.start()
        }
        println("Car is driving")
    }
}

fun main() {
    val dieselEngine = DieselEngine()
    val electricEngine = ElectricEngine()

    val car1 = Car(dieselEngine)  // Car with Diesel Engine
    car1.drive()

    val car2 = Car(electricEngine)  // Car with Electric Engine
    car2.drive()
}

```

## Dependency Injection using hilt

Constructor injection works in ViewModels, Repositories, and normal classes. Hilt is the recommended way to inject dependencies in Android.
Activities & Fragments are created by the system, so constructor injection is not possible. Instead, we use field injection with __@Inject lateinit var dependency__.

Imagine we are building a To-Do App , and our ToDoViewModel fetches tasks from a ToDoRepository.

_❌ Without Dependency Injection (Hardcoded Dependency)_

```kotlin
class ToDoRepository {
    fun getTasks(): List<String> = listOf("Buy groceries", "Finish project", "Read book")
}

class ToDoViewModel {
    private val repository = ToDoRepository()  // ❌ Hardcoded dependency

    fun fetchTasks() = repository.getTasks()
}

@Composable
fun ToDoScreen() {
    val viewModel = ToDoViewModel()  // ❌ Creating ViewModel manually
    val tasks = viewModel.fetchTasks()

    Column {
        tasks.forEach { task -> Text(task) }
    }
}
```

_Dependency Injection (Using Hilt in Jetpack Compose)_

**Define ToDoRepository**

```kotlin
class ToDoRepository @Inject constructor() {  
    fun getTasks(): List<String> = listOf("Buy groceries", "Finish project", "Read book")
}
```
**Inject ToDoRepository into  ToDoViewModel**
```kotlin
class ToDoRepository @Inject constructor() {  
    fun getTasks(): List<String> = listOf("Buy groceries", "Finish project", "Read book")
}
```
**Use them in Main function**
```kotlin
@Composable
fun ToDoScreen(viewModel: ToDoViewModel = hiltViewModel()) {  
    val tasks = viewModel.fetchTasks()

    Column {
        tasks.forEach { task -> Text(task) }
    }
}
```


## Enabling Hilt in MainActivity

Manual dependency injection can become tedious as apps grow. Connecting multiple dependencies manually leads to excessive boilerplate code. In a multi-layered architecture, creating a top-layer object requires providing all lower-layer dependencies. For example, building a car requires an engine, transmission, and chassis, while an engine itself needs cylinders and spark plugs.

### **Dependency Injection Libraries & Their Types**  

Manually managing dependencies can become complex in large apps. To simplify this, we use **Dependency Injection (DI) libraries** that automate the process.  

---

**Two Types of DI Libraries**  

**Reflection-based solutions** (e.g., **Guice**)  
   - Dependencies are resolved **at runtime**.  
   - Slower performance due to reflection.  
   - More flexible but not ideal for Android.  

**Static solutions** (e.g., **Dagger**)  
   - Dependencies are resolved **at compile time**.  
   - Faster and more efficient.  
   - Preferred for Android apps.  

---

**What is Dagger?**  
- **A dependency injection library** for Java, Kotlin, and Android.  
- **Maintained by Google** and optimized for Android.  
- **Uses compile-time DI** (instead of runtime reflection like Guice).  
- **Generates code** for dependency management, improving performance.  

---

**Why Use Dagger Over Reflection-Based DI?**  
Better Performance: No reflection, reducing runtime overhead.  
Compile-Time Safety: Errors are caught early in development.  
Optimized for Android: Works well with Android’s lifecycle.  

---

**An alternative to dependency injection is using a service locator.**

## Hilt
Hilt is Jetpack's recommended library for dependency injection in Android. Hilt defines a standard way to do DI in your application by providing containers for every Android class in your project and managing their lifecycles automatically for you.

---
### Manual

**1** _project level build.gradle.kts_
Add the hilt-android-gradle-plugin plugin to your project's root build.gradle file: 

```kotlin

plugins {
  id("com.google.dagger.hilt.android") version "2.51.1" apply false
}
```

**2** _app level build.gradle.kts_

Apply the Gradle plugin and add these dependencies in your app/build.gradle file:

```kotlin

plugins {
  id("kotlin-kapt")
  id("com.google.dagger.hilt.android")
}

android {
  ...
}

dependencies {
  implementation("com.google.dagger:hilt-android:2.51.1")
  kapt("com.google.dagger:hilt-android-compiler:2.51.1")
}

// Allow references to generated code
kapt {
  correctErrorTypes = true
}

```

**Hilt Application class**

Every app using Hilt must have an Application class annotated with **@HiltAndroidApp**.
When you add @HiltAndroidApp to your Application class, Hilt automatically generates the necessary code to manage dependency injection.

Think of it like this:
Without Hilt → You have to manually create objects and pass them everywhere in your app.
With Hilt → Hilt automatically provides the objects where they are needed.

_Without Hilt (Manual Dependency Management)_

You need an API client (Retrofit) in multiple places:
```kotlin 

class ApiClient {
    fun fetchData(): String = "Data from API"
}

class Repository {
    private val apiClient = ApiClient() // Manually creating dependency
    fun getData() = apiClient.fetchData()
}
```
Here, Repository is creating ApiClient itself → Hard to manage! 

_With Hilt (@HiltAndroidApp to Manage Dependencies)_

When we use Hilt, it creates and provides dependencies automatically:

```kotlin

@HiltAndroidApp  // 🔹 Tells Hilt to manage dependencies
class MyApp : Application() { }
```

Now, instead of creating dependencies manually, we can just ask for them using @Inject:

```kotlin

class ApiClient @Inject constructor() {  // Hilt provides this automatically
    fun fetchData(): String = "Data from API"
}

class Repository @Inject constructor(private val apiClient: ApiClient) {  // Injected by Hilt
    fun getData() = apiClient.fetchData()
}
```
Hilt automatically gives ApiClient to Repository → No manual object creation needed! 

---
But the point is here also we have to write same amount of code right??
either do this
*private val apiClient = ApiClient() // Manually creating dependency*
or 
*private val apiClient: ApiClient*

---

At first glance, it seems like we're writing the same amount of code, but **Hilt provides major benefits in larger projects**. Lets break it down clearly. 

---

**Why Use Hilt? Isn’t It the Same Code?**  

```kotlin
private val apiClient = ApiClient() // Manually creating dependency
```
**Looks similar to:**

```kotlin
private val apiClient: ApiClient // Injected by Hilt
```

BUT the real difference appears when your app grows and has many dependencies.  

---

**Small Example vs. Large Project**

**Small Example (Manually Creating Objects)**

For a **tiny app**, manually creating an object seems fine:  

```kotlin
class Repository {
    private val apiClient = ApiClient() 
}
```
But what if `ApiClient` needs another dependency, like `NetworkConfig`?  

---

**What Happens When Dependencies Grow?**

Now, **`ApiClient` also needs `NetworkConfig`**:  

```kotlin
class ApiClient(private val networkConfig: NetworkConfig) { }
```

Now, your manual creation gets messy:

```kotlin
class Repository {
    private val apiClient = ApiClient(NetworkConfig()) //  Manually creating dependencies
}
```
Imagine this happening across *10+ Classes —you would have to keep track of all dependencies manually!

---

**How Hilt Solves This Problem**
Hilt automates dependency creation and removes manual wiring.  

Say we have:

```kotlin
class NetworkConfig @Inject constructor() { 
    
}

class ApiClient @Inject constructor(private val networkConfig: NetworkConfig) { 
    fun fetchData(): String = ""
}
```

Instead of creating dependencies like this:

```kotlin
class Repository {
    private val apiClient = ApiClient(NetworkConfig())
}
```

You just declare what you need, and Hilt provides it automatically:  

```kotlin
class Repository @Inject constructor(private val apiClient: ApiClient) { 
    fun getData() = apiClient.fetchData()
}
```

Hilt sees that ApiClient needs NetworkConfig. It automatically provides NetworkConfig when ApiClient is injected.
When Repository asks for ApiClient, Hilt automatically provides it along with its dependencies.

If your app is small and has 1-2 dependencies, you might not need Hilt.  

---


**3** _Hilt Application Class_
All apps that use Hilt must contain an Application class that is annotated with @HiltAndroidApp.
Create a Class file named you Application name in same folder as MainActivity.kt.

```kotlin
@HiltAndroidApp
class ExampleApplication : Application() { 

 }
```
---

Once Hilt is set up in your Application class and an application-level component is available, Hilt can provide dependencies to other Android classes that have the @AndroidEntryPoint annotation:


**4** _Hilt AndroidEntryPoint Class_

```kotlin

@AndroidEntryPoint
class MainActivity : ComponentActivity() { //could be any class

}
```

Hilt currently supports the following Android classes:

Application (by using @HiltAndroidApp)
ViewModel (by using @HiltViewModel)
Activity
Fragment
View
Service
BroadcastReceiver

If you annotate an Android class with @AndroidEntryPoint, then you also must annotate Android classes that depend on it. For example, if you annotate a fragment, then you must also annotate any activities where you use that fragment.






