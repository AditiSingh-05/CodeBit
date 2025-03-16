# Manual

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

**3** _Hilt Application Class_
All apps that use Hilt must contain an Application class that is annotated with @HiltAndroidApp.
Create a Class file named you Application name in same folder as MainActivity.kt.

```kotlin
@HiltAndroidApp
class ExampleApplication : Application() { 

 }
```

**4** _Hilt AndroidEntryPoint Class_

```kotlin

@AndroidEntryPoint
class MainActivity : ComponentActivity() { //could be any class

}
```
