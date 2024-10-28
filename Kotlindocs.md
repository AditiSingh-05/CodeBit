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


