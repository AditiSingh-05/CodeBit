
# Project Initialization

## Step 1: Create a New Project  
Create a new project in a separate directory with the required package names.

## Step 2: Initial Run  
Run the app on an emulator or physical device to ensure everything is working properly.

## Step 3: Add Plugins and Dependencies  
Add the necessary plugins and dependencies in the `build.gradle` file.

---

## Initial Files  

### TOML File  
```kotlin
[versions]
agp = "8.6.1"
kotlin = "1.9.0"
coreKtx = "1.15.0"
junit = "4.13.2"
junitVersion = "1.2.1"
espressoCore = "3.6.1"
lifecycleRuntimeKtx = "2.8.7"
activityCompose = "1.9.3"
composeBom = "2024.12.01"

[libraries]
androidx-core-ktx = { group = "androidx.core", name = "core-ktx", version.ref = "coreKtx" }
junit = { group = "junit", name = "junit", version.ref = "junit" }
androidx-junit = { group = "androidx.test.ext", name = "junit", version.ref = "junitVersion" }
androidx-espresso-core = { group = "androidx.test.espresso", name = "espresso-core", version.ref = "espressoCore" }
androidx-lifecycle-runtime-ktx = { group = "androidx.lifecycle", name = "lifecycle-runtime-ktx", version.ref = "lifecycleRuntimeKtx" }
androidx-activity-compose = { group = "androidx.activity", name = "activity-compose", version.ref = "activityCompose" }
androidx-compose-bom = { group = "androidx.compose", name = "compose-bom", version.ref = "composeBom" }
androidx-ui = { group = "androidx.compose.ui", name = "ui" }
androidx-ui-graphics = { group = "androidx.compose.ui", name = "ui-graphics" }
androidx-ui-tooling = { group = "androidx.compose.ui", name = "ui-tooling" }
androidx-ui-tooling-preview = { group = "androidx.compose.ui", name = "ui-tooling-preview" }
androidx-ui-test-manifest = { group = "androidx.compose.ui", name = "ui-test-manifest" }
androidx-ui-test-junit4 = { group = "androidx.compose.ui", name = "ui-test-junit4" }
androidx-material3 = { group = "androidx.compose.material3", name = "material3" }
```

### Top-Level Gradle File  
```gradle
// Top-level build file where you can add configuration options common to all sub-projects/modules.
plugins {
    alias(libs.plugins.android.application) apply false
    alias(libs.plugins.kotlin.android) apply false
}
```

### App-Level Gradle File  
```kotlin
plugins {
    alias(libs.plugins.android.application)
    alias(libs.plugins.kotlin.android)
}

android {
    namespace = "com.visionforgestudio.drinkup"
    compileSdk = 35

    defaultConfig {
        applicationId = "com.visionforgestudio.drinkup"
        minSdk = 26
        targetSdk = 34
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
        vectorDrawables {
            useSupportLibrary = true
        }
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_17
        targetCompatibility = JavaVersion.VERSION_17
    }
    kotlinOptions {
        jvmTarget = "17"
    }
    buildFeatures {
        compose = true
    }
    composeOptions {
        kotlinCompilerExtensionVersion = "1.5.1"
    }
    packaging {
        resources {
            excludes += "/META-INF/{AL2.0,LGPL2.1}"
        }
    }
}

dependencies {
    implementation(libs.androidx.core.ktx)
    implementation(libs.androidx.lifecycle.runtime.ktx)
    implementation(libs.androidx.activity.compose)
    implementation(platform(libs.androidx.compose.bom))
    implementation(libs.androidx.ui)
    implementation(libs.androidx.ui.graphics)
    implementation(libs.androidx.ui.tooling.preview)
    implementation(libs.androidx.material3)
    testImplementation(libs.junit)
    androidTestImplementation(libs.androidx.junit)
    androidTestImplementation(libs.androidx.espresso.core)
    androidTestImplementation(platform(libs.androidx.compose.bom))
    androidTestImplementation(libs.androidx.ui.test.junit4)
    debugImplementation(libs.androidx.ui.tooling)
    debugImplementation(libs.androidx.ui.test.manifest)
}
```

---

## Final Files  

### Updated TOML File  
```kotlin
[versions]
agp = "8.6.1"
kotlin = "1.9.0"
coreKtx = "1.15.0"
junit = "4.13.2"
junitVersion = "1.2.1"
espressoCore = "3.6.1"
lifecycleRuntimeKtx = "2.8.7"
activityCompose = "1.9.3"
composeBom = "2024.12.01"
accompanistSystemuicontroller = "0.29.2-rc"
accompanistPermissions = "0.31.2-alpha"
coreSplashscreen = "1.0.1"
datastorePreferences = "1.1.1"
hiltAndroid = "2.51.1"
hiltNavigationCompose = "1.2.0"
lottieCompose = "5.2.0"
material3 = "1.3.1"
materialIconsExtended = "1.7.6"
navigationCompose = "2.8.5"
playServicesAds = "23.6.0"
roomRuntime = "2.6.1"
kotlinxSerializationJson = "1.6.3"
startupRuntime = "1.2.0"

# Plugins
ksp = "1.9.0-1.0.13"
hilt = "2.51.1"
serializer = "1.8.0"
relay = "0.3.12"

[libraries]
androidx-core-ktx = { group = "androidx.core", name = "core-ktx", version.ref = "coreKtx" }
androidx-compose-bom = { group = "androidx.compose", name = "compose-bom", version.ref = "composeBom" }
androidx-ui = { group = "androidx.compose.ui", name = "ui" }
androidx-ui-graphics = { group = "androidx.compose.ui", name = "ui-graphics" }
androidx-ui-tooling = { group = "androidx.compose.ui", name = "ui-tooling" }
androidx-ui-tooling-preview = { group = "androidx.compose.ui", name = "ui-tooling-preview" }
androidx-material3 = { group = "androidx.compose.material3", name = "material3" }
androidx-navigation-compose = { module = "androidx.navigation:navigation-compose", version.ref = "navigationCompose" }
androidx-room-runtime = { module = "androidx.room:room-runtime", version.ref = "roomRuntime" }
hilt-android = { module = "com.google.dagger:hilt-android", version.ref = "hiltAndroid" }
```


# Initializing Hilt

We already have our entry file called `MainActivity.kt`. For Hilt, we need to create another file, usually named `App`. In this example, we will call it `NotesApp.kt`.

## `NotesApp.kt`

```kotlin
import android.app.Application
import dagger.hilt.android.HiltAndroidApp

@HiltAndroidApp
class NotesApp: Application() {
    override fun onCreate() {
        super.onCreate()

        // TODO: Create Notification Channels Here
    }
}

```
---

__@HiltAndroidApp__ is an annotation in Hilt that is used to set up dependency injection at the application level. It tells Hilt to generate the necessary code to manage dependencies for the entire app.

---

## MainActivity.kt

```kotlin

@AndroidEntryPoint   //Set up app entry point

class MainActivity : ComponentActivity() {
    @Inject                                                 
    lateinit var userDataRepository: UserDataRepository
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {

            //Added 
            NotesTheme {
                val navController = rememberNavController() // Remembering the navigation controller
                NavGraph(navController)
            }

        }
    }


}
```
The __@Inject lateinit var userDataRepository: UserDataRepository__ is used for dependency injection in Hilt. 
__@Inject__ Annotation : Hilt automatically provides an instance of UserDataRepository when needed.
__lateinit var__ : The variable userDataRepository is not initialized at declaration but will be initialized before first use (avoiding unnecessary object creation at startup).
How It Works in __onCreate()__ : When onCreate() is called, Hilt automatically injects the userDataRepository instance before it's used.


## Manifest File

In manifest file, we have to add android app file name and also default trial id for google ads.

```kotlin

<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools">

    <application
<!--            Add this line-->
        android:name=".DrinkUpApp" 
        android:allowBackup="true"
        android:dataExtractionRules="@xml/data_extraction_rules"
        android:fullBackupContent="@xml/backup_rules"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:roundIcon="@mipmap/ic_launcher_round"
        android:supportsRtl="true"
        android:theme="@style/Theme.DrinkUp"
        tools:targetApi="31">
        <activity
            android:name=".MainActivity"
            android:exported="true"
            android:theme="@style/Theme.DrinkUp">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
<!--    Add this block -->
        <meta-data
            android:name="com.google.android.gms.ads.APPLICATION_ID"
            android:value="ca-app-pub-3940256099942544~3347511713" />
    </application>

</manifest>

```