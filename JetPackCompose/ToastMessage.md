```kotlin
@Composable
fun ToastMessage(Text: String) {
    val context = LocalContext.current
    Column(
        modifier = Modifier.fillMaxSize(),
        verticalArrangement = Arrangement.Center,
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        Button(
            onClick = {
                Toast.makeText(context, Text, Toast.LENGTH_LONG).show()
            },
            modifier = Modifier
                .width(346.dp)
                .height(56.dp),
            shape = RoundedCornerShape(16.dp),

            ) {
            Text("Toast Message")
        }
    }


}
```