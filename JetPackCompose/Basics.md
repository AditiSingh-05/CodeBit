# Simple Login Screen
```kotlin
fun LoginScreen() {
    var name by remember { mutableStateOf("") }
    var age by remember { mutableIntStateOf(0) }
}//dont close bracket only closing it to avoid error
```
_While using by in variable definetion make sure that following imports are there(cause of error)_

```kotlin
import androidx.compose.runtime.setValue
import androidx.compose.runtime.getValue
```

_Some times when you go on lines showing error you will see something like Optin API on top to avoid that error we use_
```kotlin
@OptIn(ExperimentalMaterial3Api::class)
```
## @Composable
In old methods we had XML for designing UI. @Composable does the same work in JetPack Commpose.
Whenever we have a composable function or a function block we use {} to define its content for eg:

_In the below code when we will move our cursor on Scaffold we will see a list of internal tasks it can perform
@Composable
public fun Scaffold(
    modifier: Modifier = Modifier,
    topBar: **@Composable** () -> Unit = {}, _we can see the syntax of topBar in below code it has {}_
    bottomBar:**@Composable** () -> Unit = {},
    snackbarHost: **@Composable** () -> Unit = {},
): **Unit**


_And this whole thing is a unit so we have the syntax as_

Scaffhold(_define top app bar settings_){_defined all the columns etc_}

**Now in this line**
                colors = TopAppBarDefaults.topAppBarColors().copy(
                    containerColor = Color.Blue,
                    titleContentColor = Color.White,

                    )

_We first use TopAppBarDefaults.topAppBarColors to access all the default color values but if we only take that much we will have to define all the colors by ourself but when we use .copy() we tell it to take all the default colors as its value and change only the ones that we define this way we dont encounter any error_

```kotlin 

Scaffold(
        topBar = {
            TopAppBar(
                title = { Text("My Profile") },
                //Ctrl alt L
                colors = TopAppBarDefaults.topAppBarColors().copy(
                    containerColor = Color.Blue,
                    titleContentColor = Color.White,

                    )
            )
        }
)//only closing to avoid error
```

## Codes till now

```kotlin
import {...}
import androidx.compose.runtime.getValue
import androidx.compose.runtime.setValue


@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun LoginScreen() {   
    var name by remember { mutableStateOf("") }
    var age by remember { mutableIntStateOf(0) }

    Scaffold(
        topBar = {
            TopAppBar(
                title = { Text("My Profile") },
                colors = TopAppBarDefaults.topAppBarColors().copy(
                    containerColor = Color.Blue,
                    titleContentColor = Color.White,

                    )
            )
        }
    ){.....................}
}//only closing to avoid error
```

**Short cut to import function is  alt+Shift+enter**
**short to align items by default is ctrl+alt+L**