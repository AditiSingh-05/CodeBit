
# Simple Login Screen

```kotlin
fun LoginScreen() {
    var name by remember { mutableStateOf("") }
    var age by remember { mutableIntStateOf(0) }
}//don't close bracket only closing it to avoid error
```

### _While using `by` in variable definition, make sure that the following imports are there (to avoid errors):_

```kotlin
import androidx.compose.runtime.setValue
import androidx.compose.runtime.getValue
```

_Sometimes when you go on lines showing error, you will see something like "Opt-in API" on top. To avoid that error, we use:_

```kotlin
@OptIn(ExperimentalMaterial3Api::class)
```

## `@Composable`
In old methods, we had XML for designing UI. `@Composable` does the same work in Jetpack Compose. Whenever we have a composable function or a function block, we use `{}` to define its content. For example:

_In the below code, when we move our cursor over `Scaffold`, we will see a list of internal tasks it can perform._

```kotlin
@Composable
public fun Scaffold(
    modifier: Modifier = Modifier,
    topBar: **@Composable** () -> Unit = {},  // We can see the syntax of topBar in the code, and it has {}
    bottomBar: **@Composable** () -> Unit = {},
    snackbarHost: **@Composable** () -> Unit = {},
): **Unit**
```

This whole thing is a unit, so we use the following syntax:

```kotlin
Scaffold( /* define top app bar settings */ ){ /* define all the columns etc. */}
```

### How `.copy()` Works in Jetpack Compose

In the following code:

```kotlin
colors = TopAppBarDefaults.topAppBarColors().copy(
    containerColor = Color.Blue,
    titleContentColor = Color.White,
)
```

- We use `TopAppBarDefaults.topAppBarColors()` to access all the default color values.
- If we only take that much, we would have to define all the colors ourselves.
- However, when we use `.copy()`, we are telling it to take all the default colors as its value and change only the ones we define. This way, we avoid errors.

```kotlin
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
)
```

## Full Code Example

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
    ){ 
        // Your content here
    }
}
```

### Helpful Shortcuts
- **Import function shortcut**: `Alt + Shift + Enter`
- **Align items by default**: `Ctrl + Alt + L`

```

