
# 📂 Android Project Structure  

In our package, we usually define **7 folders**, each serving a specific purpose:  

---
```
com.yourcompany.appname
│
├── core
├── domain
├── data
├── presentation
├── di
├── utils
└── navigation

```

---

## **Core**  

```
com.yourcompany.appname.core
│
├── constants     // App-wide constants (e.g., API keys, default values)
├── defaults      // Default values or configurations (e.g., themes, default states)
├── ui
│   ├── theme     // Composable theming (e.g., colors, typography, shapes)
│   ├── components // Reusable UI components (e.g., buttons, cards, dialogs)
│   └── animation // Custom animations or transitions
├── utils         // Shared utility functions (e.g., date formatters, extensions)
└── network       // Common networking logic (e.g., API clients, interceptors)
```

---

## 📌 **Domain**  
```
com.yourcompany.appname.domain
│
├── model         // Data models/entities (e.g., User, Product)
├── enums         // Enumerations (e.g., Gender)
├── interface     // Repository interfaces
└── usecase       // Use cases (e.g., FetchUserData, CalculateDiscount)
```

---

## 📌 **Data**  
```
com.yourcompany.appname.data
│
├── repository    // Repository implementations
├── datasource
│   ├── api       // Remote data source (Retrofit services, network calls)
│   ├── db        // Local database (Room DAOs, entities)
│   └── datastore // Preferences or key-value stores
└── mapper        // Mappers to transform data between layers
```

---

## 📌 **Presentation**  
```
com.yourcompany.appname.presentation
│
├── screens
│   ├── home
│   │   ├── HomeScreen.kt      // Home screen composable
│   │   ├── HomeViewModel.kt   // ViewModel for HomeScreen
│   │   └── components         // UI components specific to HomeScreen
│   ├── details
│   │   ├── DetailsScreen.kt
│   │   ├── DetailsViewModel.kt
│   │   └── components
│   └── shared                 // Shared components across multiple screens
├── navigation                 // Centralized navigation management
└── state                      // State management (e.g., ViewModels, UI states)
```

---

## 📌 **Dependency Injection (DI)**  
```
com.yourcompany.appname.di
│
├── AppModule.kt               // Application-wide dependencies
├── NetworkModule.kt           // Networking dependencies
└── DatabaseModule.kt          // Database dependencies
```

---

## 📌 **Utils**  
```
com.yourcompany.appname.utils
│
├── extensions    // Kotlin extension functions
├── validators    // Input validation logic
└── formatters    // Formatting utilities (e.g., currency, dates)
```

---

## 📌 **Navigation**  
```
com.yourcompany.appname.navigation
│
├── AppNavGraph.kt              // Centralized navigation graph
├── Destinations.kt             // Navigation destinations
└── NavigationExtensions.kt     // Helper functions for navigation
```

---

## 🛠 **Why This Structure?**  
- 📂 **Scalability** → Easy to maintain as your project grows.  
- 🔗 **Separation of Concerns** → Keeps UI, data, and domain logic independent.  
- 🏗 **Reusable Components** → Avoids code duplication and promotes reusability.  
- ⚡ **Better Testing** → Well-structured code is easier to test and debug.  

---

This structured approach ensures that your app is **clean, modular, and scalable**! 🚀  
```  

