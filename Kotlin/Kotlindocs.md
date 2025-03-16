# Kotlin
Kotlin is a modern, statically typed programming language developed bye JetBrains that runs on the Java Virtual Machine (JVM). It is designed to be fully interoperable with Java, meaning Kotlin code can call Java code and vice versa.

## Main function
Main function is the entry point of any kotlin program.

```kotlin
fun main(){
    println("hello world")

}

```
## Variables

A variable is a named storage location in memory that holds a value that can be used and manipulated throughout a program.
There are two types of variable in kotlin:
### var
It is a mutable type variable whose value can be changed after initialization.
### val 
It is a read only type variable whose value cant be changed after initialization.
```kotlin
fun main(){
    var mutable = 45
    println(mutable)
    mutable = 54
    println(mutable)
    val immutable=34
    println(immutable)
    immutable=43 //Val cannot be reassigned

    

}
```
Primitive Variables like int,string etc are stored in **Stack Memory**(_Stack memory is a memory that hold information for a short lifespan and is automatically removed once a particular function or a block of code is over_) whereas Variables like var,val that hold references to objects (like instances of classes) are stored in **Heap memory**. _(Heap memory is used for objects whose lifespan is dynamic and can outlast the function they were created in.)_

## Data Types
By default var and val already declare datatype but we can also declare it externally.

### Integer Data Type - Byte,Short,Int,Long. default is Int 

```kotlin
val Intnum1 = 32 // This is Int data type

val Intnum2 : Byte = 32 // This is Byte data type

println(Intnum1::class) // To print the data type
println(Intnum2::class)
```

### Decimals - float, double. default = double
```kotlin
val Decimalnum1 = 3.24 // double data type

val Decimalnum2 = 3.24f // float data type

val Decimalnum3: Float = 3.24F // float data type
//Both lowercase f and uppercase F work the same way in Kotlin.

println(smallDecimal1::class)
println(smallDecimal2::class)
println(smallDecimal3::class)
```

### Unsigned Integers

They cut off the negative parts and double the amount in positive direction.

They can only have positive numbers. - UByte, UShort, UInt, ULong.
```kotlin
val unsignedNumber: UShort = 44u

println(unsignedNumber::class)
```
### Boolean - Contains true, false or null
```kotlin
val myTrue = true
val myFalse = false

println(myTrue::class)
println(myFalse::class)

```

**Char** 
For storing single variable in single quotes.
```kotlin
val myChar = 'a'

println(myChar::class)

// We can also use Unicode with backslash

val anotherChar = '\u00AE'
```
**String** 
For storing group of characters in double quotes. 

```kotlin
val myString = "This is a String"

println(myString::class)
```
##Logical Operators
Logical operators also uses Boolean datatypes 

### Logical And (&&)

```kotlin
val trueAndtrue = true && true
val trueAndfalse = true && false
val falseAndfalse = false && false

println(trueOrtrue)//true
println(trueOrfalse)//true
println(falseOrfalse)//false
```
### Logical Or (||)

```kotlin
val trueOrtrue = true || true
val trueOrfalse = true || false
val falseOrfalse = false || false

println(trueAndtrue)//true
println(trueAndfalse)//false
println(falseAndfalse)//false
```
### Logical NOT (!)
```kotlin
val logicalNot = !true
println(logicalNot)//false
```

## Taking user input
```kotlin
println("Enter user entry : ")//Prompt the User for Input:
val userEntryString = readln()
//readln() reads the entire line of user input as a String. Since readln() only returns strings, the data type of userAgeString is String.
val userEntryInt = userEntryString.toInt()//conveting string data type into int
```
## Conditional Statement
### if else_if else
```kotlin
println("Enter marks:")
val marksString = readln()
val marksInt = marksString.toInt()
if (marksInt > 50){
    println("pass")
}else if (marksInt > 50 && marksInt < 80){
    println("You can perform better")
}else{
    println("Excellent")
}
```
### while loop
```kotlin
var num = 0
    while (num < 5){
        println("While loop ran $num times")
        num++
    }
```
### Uppercase and lowercase conversion
```kotlin
println("Enter choice: ")
var anything = readln()
println(anything.uppercase())
```
## Functions
_function name is written as **letTheFunctionName** in standard form_

### 1.Basic function syntax
To define a function in kotlin use the **fun** keyword followed by the function name, parameters, and body.
```kotlin
fun greet(){
    println("Greetings")
}
fun main(){
    greet() //prints Greeting
}
```
### Function with parameters
Passing parameters with function passing there type in bracket.
Functions can have parameters with default values, which are used if no argument is provided.


```kotlin

fun greet(name : String = "Ad"){
    println("Hello, $name!!")

}
fun main(){
    greet()//Hello, Ad
    greet("Aditi")//prints Hello, Aditi!!
}
```
### Function with return type
Specify the return type after the parameters, using a colon.
```kotlin
fun add(a: Int, b: Int): Int {
    return a + b
}

fun main() {
    val result = add(5, 3) // result is 8
    println(result) // Output: 8
}
```
### Single expression Functions
Kotlin allows you to write functions with a single expression concisely, using = instead of {}.
```kotlin
fun multiply(a: Int, b: Int): Int = a * b

fun main() {
    println(multiply(4, 5)) // Output: 20
}
```
### Named Arguments
Can specify parameters by name when calling a function, making it easier to read and avoiding parameter order issues.
```kotlin
fun details(name: String, age: Int) {
    println("Name: $name, Age: $age")
}

fun main() {
    details(age = 21, name = "Aditi") // Output: Name: Aditi, Age: 21
}
```
### Vararg parameters(Variable length Arguments)

If you want to pass a variable number of arguments to a function, you can use the vararg keyword.
```Kotlin
fun displayNumbers(vararg numbers: Int) {
    for (number in numbers) {
        println(number)
    }
}

fun main() {
    displayNumbers(1, 2, 3, 4) // Output: 1 2 3 4 (each on a new line)
}
```

###  Lambda Functions and Higher-Order Functions

Kotlin functions can accept other functions as parameters or return them, known as higher-order functions. Lambda expressions are used to define functions concisely.
A lambda function is an anonymous function, meaning it doesn’t have a name. Lambda functions are typically used as concise expressions that can be passed as arguments to other functions.
**{ parameters -> body }** _defined within curly brackets_
Can also be used like
```kotlin
val sum = { a: Int, b: Int -> a + b }
println(sum(3, 4)) // Output: 7
```

**Or**

```kotlin
fun calculate(a: Int, b: Int, operation: (Int, Int) -> Int): Int {
    return operation(a, b)
}

fun main() {
    val sum = calculate(3, 5) { x, y -> x + y } // Using lambda for addition
    println(sum) // Output: 8
}
```
***Using lambda in higher order function**
Higher-order functions are functions that take other functions as parameters or return them. Lambdas are often used in higher-order functions, such as Kotlin's map, filter, and forEach.
```kotlin
val numbers = listOf(1, 2, 3, 4, 5)
val doubled = numbers.map { it * 2 } // Lambda that doubles each element
println(doubled) // Output: [2, 4, 6, 8, 10]
```
Here, { it * 2 } is a lambda expression. The keyword it represents the single parameter passed to the lambda, which is each element in the numbers list.

### Inline function
### Extension function
Lets you add new functionality to existing classes without modifying their source code or creating subclasses. This is particularly useful for adding utility functions to standard classes, like String or List, or even your custom classes.
```kotlin
fun String.addExclamation(): String {
    return this + "!"
}

fun main() {
    println("Hello".addExclamation()) // Output: Hello!
}
```
**Use example :** 
```kotlin
class Car(val make: String, val model: String)

// Extension function for Car class
fun Car.getCarInfo(): String {
    return "$make $model"
}

fun main() {
    val car = Car("Toyota", "Corolla")
    println(car.getCarInfo()) // Output: Toyota Corolla
}
```
## **Class** 
**A blueprint that is used to create objects. Classes can have constructors, initializers, functions, etc.**
_In this Kotlin code, we define a Dog class with some properties, an initializer block, and a function to simulate the dog's bark._
_The init block is an initializer block that runs when an instance of the class is created._
_Here, it calls the bark function with name as an argument, making the dog bark (i.e., print a message) immediately upon creation._

```kotlin
class Dog(val name: String, val breed: String?, val age: Int = 2){

    init {
        bark(name)
    }

    fun bark(name: String){
        println("$name says woof woof")
    }
}

fun useDogClass() {
    var myDog = Dog(name = "Shadow", breed = "Retriever")//output is Shadow says woof woof bcs the init block of class callse bark()
}
```
### Data Class

Used for storing data, they have some default functions like .toString, .copy etc

```kotlin
data class Coffee(var coffeeSize: String = "M", var sugar: Int = 2, var withCream: Boolean = true)
```
# Advanced Kotlin
## List
**Immutable List (listOf)**
An immutable list is a read-only list, meaning you cannot add, remove, or modify its elements once it’s created.You can access elements, check size, and perform read-only operations.
```kotlin
val immutableList = listOf("Apple", "Banana", "Cherry")
println(immutableList) // Output: [Apple, Banana, Cherry]

// Access elements
println(immutableList[1]) // Output: Banana

// Try to modify (not allowed)
// immutableList.add("Date") // Error: Unresolved reference: add
```
**Mutable List(mutablelistof)**
A mutable list allows modification, so you can add, remove, or update elements after creating it. Operations Allowed: All operations that modify the list, like adding, removing, or setting elements at specific indices..

```kotlin
val mutableList = mutableListOf("Dog", "Cat", "Bird")
println(mutableList) // Output: [Dog, Cat, Bird]

// Modify the list
mutableList.add("Fish")
mutableList.remove("Cat")
mutableList[0] = "Horse"

println(mutableList) // Output: [Horse, Bird, Fish]
```

**For loop in list**
```kotlin
fun forLoop(){
    val mutableList = mutableListOf("Processor", "RAM", "Graphic Cards", "SSD", "HD")

    for(item in mutableList){
        println(item)
    }

    // Breaking loop

    for(item in mutableList){
        println(item)
        if(item == "RAM"){

            break
        }
    }

    // using index in loop

    for (item in 0 until mutableList.size){
        println(item)
        println(mutableList[item])
    }
}
```