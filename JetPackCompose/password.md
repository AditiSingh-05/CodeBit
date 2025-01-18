# Password Setup Feature

## Overview
This document explains the password setup functionality implemented in the `LoginScreen`. The feature allows users to create and manage secure passwords by implementing visibility toggling and password length validation.

## Key Features
1. **Password Visibility Toggle**: Users can toggle password visibility between asterisks (hidden) and plain text (visible).
2. **Password Length Validation**: Ensures the password is at least 6 characters long and provides real-time feedback to the user.

## Implementation Details

### 1. Password Field
The password field is implemented using `OutlinedTextField` in Jetpack Compose, which handles the user input for the password. It includes features such as:

- **Keyboard Type**: The keyboard type is set to `KeyboardType.Password`, which restricts input to a password format.
- **Visual Transformation**: The password field initially displays a hidden password using dots (via `PasswordVisualTransformation`). When the user taps on the eye icon, it switches to show the password in plain text.

### 2. Password Visibility Toggle
The visibility of the password is controlled by a boolean variable `passwordVisible`. 

- When `passwordVisible.value` is `true`, the password is shown in plain text.
- When `passwordVisible.value` is `false`, the password is displayed as dots (i.e., masked).
  
The password visibility toggle is achieved through the `trailingIcon` in the `OutlinedTextField`, which uses an `IconButton` with an eye icon (`visible` or `notvisible`) to switch the state.

### 3. Password Length Validation
A password length check is performed as soon as the user inputs a password. If the password length is less than 6 characters, an error message is displayed below the password field.

## Code Implementation

```kotlin
@Composable
fun PasswordTextField() {
    val password = remember { mutableStateOf("") }
    val passwordVisible = remember { mutableStateOf(false) }

    OutlinedTextField(
        value = password.value,
        onValueChange = { password.value = it },
        label = { Text("Password") },
        keyboardOptions = KeyboardOptions(keyboardType = KeyboardType.Password),

        visualTransformation = if (passwordVisible.value) {  
            VisualTransformation.None
        } else {                                             
            PasswordVisualTransformation()
        },

        trailingIcon = {
            val image = if (passwordVisible.value) {
                painterResource(id = R.drawable.visible) 
            } else {
                painterResource(id = R.drawable.notvisible) 
            }
            IconButton(onClick = {
                passwordVisible.value = !passwordVisible.value
            }) {
                Icon(painter = image, contentDescription = null)
            }
        }
    )

    if (password.value.length < 6) {
        Text(
            text = "Password must be at least 6 characters",
            color = MaterialTheme.colorScheme.error,
            modifier = Modifier.padding(top = 8.dp)
        )
    }
}
