JavaScript Objects
At their core, objects are just mappings from strings to other values. The values can be anything: strings, functions, other objects, etc. The string that maps to the value is called the key.

const object = {
  "num": 1,
  "str": "Hello World",
  "obj": {
    "x": 5
  }
};
There are three ways to access values on an object:

Dot Notation.
const val = object.obj.x;
console.log(val); // 5
Bracket Notation. This is used when the key isn't valid variable name. For example ".123".
const val = object["obj"]["x"];
console.log(val); // 5
Destructuring Syntax. This is most useful when accessing multiple values at once. You can read more about the syntax here.
const { num, str} = object;
console.log(num, str); // 1 "Hello World"
You can read more about objects here.

Classes and Prototypes
You can also define classes in JavaScript. The classes's constructor returns an object which is an instance of that class.

class Person {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  greet() {
    console.log("My name is", this.name);
  }
}

const alice = new Person("Alice", 25);
alice.greet(); // Logs: "My name is Alice"
JavaScript implements classes with special objects call prototypes. All the methods (in this case greet) are functions stored on the object's prototype.

To make this concrete, the behavior of the above code could be replicated with the following code:

const alice = {
  name: "Alice",
  age: 25,
  __proto__: {
    greet: function() {
      console.log("My name is", this.name);
    }
  }
};
alice.greet(); // Logs: "My name is Alice"
Looking at this code, you might wonder "How can you access the greet method even though it's not a key on the alice object"?

The reason is that accessing keys on an object is actually slightly more complicated than just looking at the object's keys. There is actually an algorithm that traverse the prototype chain. First, JavaScript looks at the keys on the object. If the requested key wasn't found, it then looks on the keys of the prototype object. If it still wasn't found, it looks at the prototype's prototype, and so on. This is how inheritance is implemented in JavaScript!

You might also wonder why JavaScript has this strange prototype concept at all. Why not just store the functions on the object itself? The answer is efficiency. Every time a new Person is created, age and name fields are added to the object. However only a single reference to the prototype object is added. So no matter how many instances of Person are created or how many methods are on the class, only a single prototype object is generated.

You can read more about classes here.

Proxies
An infrequently used but powerful feature of javascript is the proxy. They allow you to override the default behavior of objects.

For example, to implement the alice object with proxies:

const alice = new Proxy({name: "Alice", age: 25}, {
  get: (target, key) => {
    if (key === 'greet') {
      return () => console.log("My name is", target.name);
    } else {
      return target[key];
    }
  },
});
alice.greet(); // Logs: "My name is Alice"
Examples
Here are some examples of potentially practical use-cases for proxies.

Perform validation to guarantee bad data is never entered into a form.
Perform validation to guarantee bad data is never entered into a form.
Code Example
const validator = {
  set: (obj, prop, value) => {
    if (prop === "age") {
      if (typeof value !== "number" || value < 0) {
        throw new TypeError("Age must be a positive number");
      }
    }
    obj[prop] = value;
  },
};

const person = new Proxy({}, validator);
person.age = 25; // Works fine
person.age = -5; // Throws an error

Create a log any time a key is accessed. This could be useful as a developer tool.
Code Example
const object = {
  "num": 1,
  "str": "Hello World",
  "obj": {
    "x": 5
  }
};
const proxiedObject = new Proxy(object, {
  get: (target, key) => {
    console.log("Accessing", key);
    return target[key];
  }
});
proxiedObject.num; // Logs: Accessing num

Throw an error if a an attempt was made to write to a readonly value.
Code Example
const READONLY_KEYS = ['name'];

const person = new Proxy({ name: "Alice", age: 25 }, {
  set: (target, key, value) => {
    if (READONLY_KEYS.includes(key)) {
      throw Error("Cannot write to key");
    }
    target[key] = value;
    return true;
  }
});
person.name = "Bob"; // Throws Error

Create a modified version of an immutable object by writing to it's proxy. This is implemented with the popular library immer.
You can read more about proxies here.
[immer](https://immerjs.github.io/immer/)
[destructing obj](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment)
[obj js](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Working_with_objects)



<br><br><br>

Truthy and Falsy
In this question, you are asked to remove all values from an array that aren't truthy (i.e. remove all falsy values). But what does that mean? JavaScript has true boolean values of true and false. But you are actually allowed to put any value inside an if statement. That value will be coerced into a boolean based on it's "truthiness".

All values are considered truthy except the following:

false
All forms of zero, meaning 0, -0 (output of 0/-1), and 0n (output of BigInt(0))
NaN ("Not a Number", one way to get it is with 0/0)
"" (empty string)
null
undefined
Why does this language feature exist?
The short answer is it can be convenient. Imagine you have a textfield which edits a variable userInput which is initially null.

Rather than writing:

if (userInput !== null && userInput !== "") {
  // uploadToDatabase(userInput)
}
You can shorten this to:

if (userInput) {
  // uploadToDatabase(userInput)
}
However, it is easy to not think carefully about your code and create bugs by not being explicit about what values are valid. For example, zero or an empty string might be completely valid inputs and the above code will result in a bug.

Truthiness and Logical Operators
It is not uncommon to see code like this in a JavaScript codebase:

const stringVal = textInput || "Default Value";
To an experienced JavaScript developer, this makes perfect sense. But developers from other backgrounds might find this very confusing. Why is a logical operator returning a string?

This is because, in JavaScript, logical operators don't return booleans; they return one of the two operands provided to them. At first this is confusing, but it is actually quite elegant and allows you to write very terse code.

The OR operator || returns the first value if the first value is truthy (without evaluating the 2nd value). Otherwise it returns the second value.
The AND operator && returns the first value if the first value is falsy (without evaluating the 2nd value). Otherwise it returns the 2nd value.
The Nullish Coalescing operator ?? is identical to || except it only treats null and undefined as falsy.
An easy way to remember this is by knowing the logical operator will return the last value it needed to evaluate. For example, OR is immediately true if the first value is true, thus it will return the first value iff it is truthy.

The reason this is elegant is because for true booleans, this algorithm actually works exactly as you would expect. Try it out for yourself! However you can also use them to write short code for non-boolean operations. And even if you don't use these operators for that purpose yourself, it's important to understand them for reading other's code.

A common use-case is for choosing the first truthy value from a list:

let val;
if (a) {
  val = a;
} else if (b) {
  val = b;
} else {
  val = c;
}
can be replaced with:

const val = a || b || c;
You could also conditionally execute some code:

if (a && b) {
  func();
}
can be replaced with:

a && b && func();
Built-in Array.filter
This question asks you to reimplement the Array.filter method, which is one of the most heavily used array methods in JavaScript. However there are four small differences between your implementation and the standard library.

Array.filter is a method on the Array prototype. This implementation is a function that accepts the array as the 1st argument.
The callback passed to Array.filter has a reference to the original array passed as the 3rd argument. This implementation's callback only accepts two arguments.
Array.filter optionally allows you pass a thisArg as the 2nd parameter. If provided, the passed callback will be bound to that context (assuming the callback isn't an arrow function as they can't be bound).
Array.filter handles sparse arrays. For example, if you write code let arr = Array(100); arr[1] = 10;, Array.filter will only look at index 1 and the empty indices will automatically be filtered out.