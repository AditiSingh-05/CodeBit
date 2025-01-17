# Navigation in Jetpack Compose

This guide explains how navigation is set up in Jetpack Compose using the `NavController`, `NavHost`, and `sealed class AppScreens` to manage app screens.

## Dependencies
```kotlin
val nav_version = "2.8.5"

    implementation("androidx.navigation:navigation-compose:$nav_version")

```

## Sealed Class for Screens
```kotlin
package com.example.montra

sealed class AppScreens(val route: String) {
    object FirstScreen : AppScreens("Alias Name") 
    object SecondScreen : AppScreens("Alias Name")
    object ThirdScreen : AppScreens("Alias Name")
}
```
A sealed class is used to represent a restricted class hierarchy, where a class can only be subclassed within the same file.
In this example, each screen is represented as an object inheriting from AppScreens, with a route value that defines the screen's identifier.

## Creating the NavGraph
```kotlin
@Composable
fun NavGraph(navController: NavController) {
    val navController = rememberNavController() // Navigation controller
    NavHost(navController, startDestination = AppScreens.FirstScreen.route) {
        composable(AppScreens.FirstScreen.route) {
            FirstScreenMainFunctionName(navController)
        }
        composable(AppScreens.SecondScreen.route) {
            SecondScreenMainFunctionName(navController)
        }
        composable(AppScreens.ThirdScreen.route) {
            ThirdScreenMainFunctionName(navController)
        }
    }
}
```
NavHost is a Composable used to define the navigation graph of the app.
It holds composable destinations (FirstScreen, SecondScreen, etc.) and determines the screen to display based on the current route.

NavController is responsible for navigating between different composables (screens) in Jetpack Compose.
It's used to navigate to different screens and pass arguments between them.
rememberNavController() is used to create a navigation controller that survives recompositions in Composables.

## MainActivity Setup

```kotlin
class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge() // Edge-to-edge UI setup
        setContent {
            val navController = rememberNavController() // Remembering the navigation controller
            NavGraph(navController) // Calling the NavGraph composable
        }
    }
}
```
setContent is used to set the UI content for the Activity. In this case, it initializes the navigation by calling the NavGraph composable.
This method is used to extend the content of the app to the edges of the screen, making the UI feel immersive.

## Screen-Specific Changes
```kotlin
fun FirstScreenFunction(navController: NavController) {
    // Implementation of the screen UI goes here
}
```
Each screen (like FirstScreen, SecondScreen, ThirdScreen) should have a function that takes NavController as a parameter to manage navigation actions from that screen.

## onClick Navigation
```kotlin
onClick = { navController.navigate(AppScreens.NavigationScreen.route) }
```
