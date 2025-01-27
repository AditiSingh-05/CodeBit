# README for Enhanced BasePage with Drawer and Pager

## Overview

This project demonstrates a **BasePage** built using Jetpack Compose with enhancements:
1. A **Navigation Drawer** with menu options.
2. A **Horizontal Pager** displaying dynamic, personalized content.
3. A modern **TopAppBar** and Material Design components.

---

## Features

### **1. Navigation Drawer**
The drawer provides seamless navigation with clickable options.

```kotlin
@Composable
fun DrawerContent(drawerState: DrawerState) {
    Column(
        modifier = Modifier
            .fillMaxWidth()
            .padding(16.dp),
        verticalArrangement = Arrangement.spacedBy(16.dp)
    ) {
        Text(
            text = "Navigation",
            style = MaterialTheme.typography.headlineMedium,
            modifier = Modifier.padding(bottom = 8.dp)
        )
        Divider()

        DrawerOption(Icons.Default.Person, "Profile", onClick = { /* Handle Profile Click */ })
        DrawerOption(Icons.Default.Menu, "Settings", onClick = { /* Handle Settings Click */ })
        DrawerOption(Icons.Default.Menu, "About", onClick = { /* Handle About Click */ })
    }
}

@Composable
fun DrawerOption(icon: androidx.compose.ui.graphics.vector.ImageVector, label: String, onClick: () -> Unit) {
    Row(
        modifier = Modifier
            .fillMaxWidth()
            .padding(8.dp)
            .clickable { onClick() },
        verticalAlignment = Alignment.CenterVertically
    ) {
        Icon(icon, contentDescription = label, modifier = Modifier.size(24.dp))
        Spacer(modifier = Modifier.width(16.dp))
        Text(text = label, style = MaterialTheme.typography.bodyLarge)
    }
}
```

---

### **2. Horizontal Pager**
The pager enables dynamic page navigation with an indicator.

```kotlin
@OptIn(ExperimentalPagerApi::class)
@Composable
fun BasePageWithDrawerAndPager(userName: String) {
    val drawerState = rememberDrawerState(initialValue = DrawerValue.Closed)
    val pagerState = rememberPagerState()

    ModalNavigationDrawer(
        drawerState = drawerState,
        drawerContent = {
            DrawerContent(drawerState)
        },
        content = {
            Scaffold(
                topBar = {
                    TopAppBar(
                        title = { Text(text = "Home") },
                        navigationIcon = {
                            IconButton(onClick = { drawerState.open() }) {
                                Icon(Icons.Filled.Menu, contentDescription = "Menu")
                            }
                        }
                    )
                },
                content = { paddingValues ->
                    Column(
                        modifier = Modifier
                            .fillMaxSize()
                            .padding(paddingValues)
                    ) {
                        // Greeting Text
                        Text(
                            text = "Welcome, $userName!",
                            style = MaterialTheme.typography.headlineLarge,
                            modifier = Modifier.padding(16.dp)
                        )

                        Spacer(modifier = Modifier.height(16.dp))

                        // Pager Section
                        HorizontalPager(
                            count = 3, // Number of pages
                            state = pagerState,
                            modifier = Modifier.weight(1f)
                        ) { page ->
                            when (page) {
                                0 -> MotivationPage("“Push yourself, because no one else is going to do it for you.”")
                                1 -> GoalPage("Set your goals and crush them!")
                                2 -> AchievementsPage("Your achievements deserve celebration!")
                            }
                        }

                        Spacer(modifier = Modifier.height(16.dp))

                        // Pager Indicator
                        HorizontalPagerIndicator(
                            pagerState = pagerState,
                            modifier = Modifier
                                .align(Alignment.CenterHorizontally)
                                .padding(16.dp)
                        )
                    }
                }
            )
        }
    )
}
```

---

### **3. Individual Pages**
Each page is personalized with unique content.

#### Motivation Page
```kotlin
@Composable
fun MotivationPage(quote: String) {
    Box(
        modifier = Modifier
            .fillMaxSize(),
        contentAlignment = Alignment.Center
    ) {
        Text(
            text = quote,
            style = MaterialTheme.typography.bodyLarge,
            modifier = Modifier.padding(16.dp)
        )
    }
}
```

#### Goal Page
```kotlin
@Composable
fun GoalPage(prompt: String) {
    Box(
        modifier = Modifier
            .fillMaxSize(),
        contentAlignment = Alignment.Center
    ) {
        Text(
            text = prompt,
            style = MaterialTheme.typography.bodyLarge,
            modifier = Modifier.padding(16.dp)
        )
    }
}
```

#### Achievements Page
```kotlin
@Composable
fun AchievementsPage(message: String) {
    Box(
        modifier = Modifier
            .fillMaxSize(),
        contentAlignment = Alignment.Center
    ) {
        Text(
            text = message,
            style = MaterialTheme.typography.bodyLarge,
            modifier = Modifier.padding(16.dp)
        )
    }
}
```

---

## Customization

1. **Add More Pages**: Modify `HorizontalPager` count and include additional composables.
2. **Drawer Options**: Add more options in `DrawerContent`.
3. **Theme**: Apply custom Material Design styling.

---

## Prerequisites

1. Android Studio Arctic Fox or newer.
2. Accompanist Pager library in your dependencies.

---

## Getting Started

1. Clone the repository.
2. Open it in Android Studio.
3. Sync dependencies and run the project.

---

## Future Enhancements

- Add deep links for drawer options.
- Enable animations for smooth navigation.
- Fetch page content dynamically using APIs.

--- 

Feel free to use this as a reference or adapt it for your needs!