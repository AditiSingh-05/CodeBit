```kotlin

@Composable
fun SplashScreen(){
    LaunchedEffect (Unit){
        delay( 3000L)
//        navController.navigate(AppScreens.LoginScreen.route)
    }
    Box(
        modifier = Modifier.fillMaxSize(),

    ){
        Image(
            painter = painterResource(id = R.drawable.splashscreenimage),
            contentDescription = "Splash Screen",
            modifier = Modifier.fillMaxSize()
        )

    }
}

```