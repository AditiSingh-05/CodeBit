# Object
---
Lets say we have a _Car_ as an object, it will have different _Attributes/Properties_ and _Behaviour/Function_.

Now this object must have a blueprint.\

# Class
--- 
Class is _Blueprint_ of an Object

```kotlin
class Car{               //Car is an blueprint for all the car objects

    //Attributes/Properties
    var color : String = "Red"

    //Behaviour/Function
    fun drive(){
        print("driving.........")
    }
}


fun main(){
    val car1 = Car()     //Here car1 is an object made  using blueprint Car
    print(car1.color)    //Output = Red
    car1.color = "Blue"
    print("car1 color : ${car1.color}")    //Output = Blue


    car1.drive()
}

```
__Passing by default constructor__

```kotlin
class Car(color:String = "Blue"){
    var color : String = color
}

fun main(){
    val car1 = Car(color = "Green")
}
```