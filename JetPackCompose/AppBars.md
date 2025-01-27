
This guide demonstrates how to implement a **Top App Bar** with a menu icon and a **Bottom App Bar** with a **plus icon** in Jetpack Compose.

## 1. Top App Bar with Menu Icon

The **Top App Bar** typically contains a title and a navigation icon (like a hamburger menu icon) for drawer functionality.

### Code:

```kotlin
@Composable
fun TopAppBarWithMenu(navController: NavController) {
    Scaffold(
        topBar = {
            TopAppBar(
                title = { Text("Home") },
                navigationIcon = {
                    IconButton(onClick = { /* Handle drawer open */ }) {
                        Icon(Icons.Default.Menu, contentDescription = "Menu Icon")
                    }
                }
            )
        }
    ) { screenPadding ->
        Column(
            modifier = Modifier.padding(screenPadding)
        ) {
            Text("Welcome to the Home Screen!")
        }
    }
}
```

### Explanation:
- The `TopAppBar` has a title ("Home") and a **menu icon** (`Icons.Default.Menu`).
- The **IconButton** inside the `navigationIcon` triggers the drawer to open when clicked.

## 2. Bottom App Bar with Plus Icon

The **Bottom App Bar** is typically used for actions like adding content or performing tasks. In this example, it contains a **plus icon** (`Icons.Default.Add`).

### Code:

```kotlin
@Composable
fun BottomAppBarWithPlusIcon() {
    Scaffold(
        bottomBar = {
            BottomAppBar(
                actions = {
                    IconButton(onClick = { /* Handle action for plus icon */ }) {
                        Icon(Icons.Default.Add, contentDescription = "Add")
                    }
                }
            )
        }
    ) { screenPadding ->
        Column(
            modifier = Modifier.padding(screenPadding)
        ) {
            Text("Welcome to the Home Screen!")
        }
    }
}
```

### Explanation:
- The **BottomAppBar** contains an `IconButton` with a **plus icon** (`Icons.Default.Add`).
- The **IconButton** is used to define actions that happen when the plus icon is clicked, such as opening a dialog or navigating to a new screen.

## 3. Combining Both Bars in Home Screen

You can use both the **TopAppBar** and **BottomAppBar** together in your `HomeScreen` to create a layout with a drawer, top bar, and bottom bar.

### Code:

```kotlin
@Composable
fun HomeScreen(navController: NavController) {
    BasePage(
        navController = navController,
        title = "Home",
        content = {
            Text("Welcome to the Home Screen!")
        }
    )
    
    Scaffold(
        bottomBar = {
            BottomAppBar(
                actions = {
                    IconButton(onClick = { /* Handle click for plus icon */ }) {
                        Icon(Icons.Default.Add, contentDescription = "Add")
                    }
                }
            )
        }
    ) { screenPadding ->
        Column(
            modifier = Modifier.padding(screenPadding)
        ) {
            // Any additional content for the Home Screen goes here
        }
    }
}
```

### Explanation:
- The `HomeScreen` uses the `BasePage` for the top app bar and drawer, and the `Scaffold` is used to add the bottom app bar with the plus icon.
- The **BottomAppBar** with the **plus icon** is shown at the bottom of the screen.

## Conclusion

With these two implementations, you now have:
1. A **Top App Bar** with a **menu icon** for drawer functionality.
2. A **Bottom App Bar** with a **plus icon** for performing actions.

