# BasePage Composable Documentation

This README provides an explanation of the `BasePage` Composable function, which serves as a reusable layout for screens in a Jetpack Compose-based Android application. It incorporates navigation, a drawer, and a scaffold for flexible UI development.

---

## Overview

The `BasePage` composable encapsulates common UI elements such as:

1. **Navigation Drawer**: For quick access to various routes in the application.
2. **Scaffold**: Provides a structured UI layout including a top bar and content area.
3. **Composable Slot**: A slot to dynamically inject screen-specific content.

---

## Code Structure

### 1. **Function Definition**

```kotlin
@Composable
fun BasePage(
    navController: NavController,
    title: String,
    content: @Composable () -> Unit,
)
```

- **Parameters**:
  - `navController`: Handles navigation between screens.
  - `title`: Title of the current screen, used in the UI.
  - `content`: A composable lambda to define the main screen's content.

---

### 2. **Drawer State and Scope**

```kotlin
val drawerState = rememberDrawerState(initialValue = DrawerValue.Closed)
val scope = rememberCoroutineScope()
var selectedPage = remember { mutableStateOf("Selected Page") }
```

- `drawerState`: Tracks whether the drawer is open or closed.
- `scope`: Provides a coroutine scope to perform asynchronous operations like opening/closing the drawer.
- `selectedPage`: Maintains the state of the currently selected page.

---

### 3. **Drawer Item Click Handler**

```kotlin
fun onDrawerItemClick(route: String) {
    scope.launch {
        drawerState.close()
    }
    navController.navigate(route)
    selectedPage.value = route
}
```

- **Purpose**: Handles the click events for drawer items.
- **Steps**:
  1. Closes the drawer asynchronously.
  2. Navigates to the selected route using `navController`.
  3. Updates the `selectedPage` state.

---

### 4. **ModalNavigationDrawer**

```kotlin
ModalNavigationDrawer(
    drawerState = drawerState,
    drawerContent = {
        ModalDrawerSheet(
            // Drawer decoration
        ) {
            // Drawer content
        }
    }
)
```

- **Purpose**: Defines the navigation drawer.
- **Key Components**:
  - `ModalDrawerSheet`: A sheet inside the drawer for adding content like menu options.

---

### 5. **Scaffold**

```kotlin
Scaffold(
    // Top bar and other UI components
) { ScreenPadding ->
    Box(
        modifier = Modifier.padding(ScreenPadding)
    ) {
        // Content from the 'content' parameter is placed here
    }
}
```

- **Purpose**: Provides a structured layout with a top bar and padding for the main content.
- **Key Feature**: Injects the passed `content` composable inside the layout.

---

### 6. **DrawerOption Composable**

```kotlin
@Composable
fun DrawerOption(
    onItemClick: () -> Unit,
    title: String,
    modifier: Modifier = Modifier
) {
    Row(
        // Row decorations
    ) {
        // Add an icon and text for the drawer option
    }
}
```

- **Purpose**: Represents a single item in the drawer.
- **Parameters**:
  - `onItemClick`: Callback for click events.
  - `title`: Text for the drawer option.
  - `modifier`: Custom styling for the row.

---

## Example Usage

### BasePage Implementation

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
}
```

### DrawerOption Usage

```kotlin
DrawerOption(
    onItemClick = { /* Navigate to a specific route */ },
    title = "Settings"
)
```

---

## Notes

- **Customizations**: Extend the `ModalDrawerSheet` and `Scaffold` sections to meet specific UI requirements.
- **Error Handling**: Ensure proper navigation handling to avoid crashes on invalid routes.
- **Design**: Add icons, animations, or styling as needed for drawer options and top bar.

