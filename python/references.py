#!/usr/bin/env python

import textwrap
import sys
import warnings

#
# Memory management
#

memory_layout = """\

                    ✨ Welcome to the Magical
                        World of Python Memory
                            Management ✨

    +----------------------+          +------------------------------+
    |                      |          | Interned Strings Dictionary: |
    |      Code Segment    |          | +-----------+--------+       |
    |                      |          | | Key       | Value  |       |
    |  Bytecode for funcs, |          | +-----------+--------+       |
    |  classes, and modules|          | | "hello"   | addr1  |       |
    |                      |          | | "world"   | addr2  |       |
    +----------------------+          | +-----------+--------+       |
    |                      |          |                              |
    |    Static Segment    |          | Small Integers Array:        |
    |                      |          | +------+--------+            |
    |  static/global vars  |          | | Index| Value  |            |
    |  (global constants), |          | +------+--------+            |
    |  string literals&    |          | |  -5  | addr3  |            |
    |                      |          | |  ... | ...    |            |
    +----------------------+          | | 100  | addr4  |            |
    |----------------------|          | |  ... | ...    |            |
    |      Heap Segment    |          | | 256  | addr5  |            |
    |----------------------|          | +------+--------+            |
    |  Objects             |          +------------------------------+
    |  Containers          |
    |  Non-interned Strings|
    |  Interned Strings*   |
    |  Small Integers*     |    * Part of global cache created during runtime initialization
    |  Modules             |
    |  Functions           |    & Static String Literals are embedded directly in the code and
    |  Global Variables    |      typically reside in the static segment.
    |  Class Definitions   |
    +----------------------+      These strings have fixed memory locations and are read-only.
    |----------------------|
    |     Stack Segment    |
    |----------------------|
    |  Function Call Frames|
    |  Local Variables     |
    |  Control Flow Info   |
    +----------------------+

"""


#
# Shared references
#

num1 = 5
num2 = 5

def demo_literals_with_ids(expr1, expr2):
    with warnings.catch_warnings():
        warnings.simplefilter("ignore")
        return expr1 is expr2

a = "hello"
b = "hello"
c = sys.intern("hello world")
d = sys.intern("hello world")

str1 = "hello"
str2 = "world"
concatenated_str = str1 + str2

literal_ref = '''\
/*******************
  Literal References
  ******************/

Let's address 5 to variable num1 and 5 to num2.

num1 = 5
num2 = 5

These are distinct (non-shared) assignments. Yet they point to the same memory location.

Address of 'num1': {adr1}
Address of 'num2': {adr2}

Hence, the identity operator returns True.

num1 is num2 == {simple_is}

/*****************
  Literal Caching
  ****************/

Python employs an optimization technique known as literal caching:
- Python maintains an internal dictionary for the interned literals cache, which stores and
  retrieves these frequently used immutable objects efficiently.
- Small integers (from -5 to 256) are preallocated and stored in a global cache. NO OTHERS CAN BE
  EXPLICITLY CACHED.
- Frequently used string literals, especially those that resemble identifiers, are interned to
  save memory and improve performance.
- Details differ by CPython's implementation

Integer 4:                 {literal_ex1}
String 'asdf':             {literal_ex2}
Comparison '4 is 4':       {literal_ex3}
Comparison 'asdf is asdf': {literal_ex4}

/*************
  String Talk
 *************/

While many strings literals or expressions from literals are automatically cached, we can
explicitly force caching into the global literal cache as well:

a = "hello"                     {addr_a}
b = "hello"                     {addr_b}
c = sys.intern("hello world")   {addr_c}
d = sys.intern("hello world")   {addr_d}

Runtime details of Python's literal interning algorithm:
- Strings are immutable which enables easier shared references
- Strings like 'hello' are automatically interned, hence 'a is b' evaluates to True.

This extends to expressions:


str1 = "hello"
str2 = "world"
concatenated_str = str1 + str2

concatenated_str is "helloworld" == {concat_ex}


- Forcing interning using sys.intern():
  'hello world': {interned_ex1}
  'hello world': {interned_ex2}
  Comparison 'c is d': {interned_ex3}

In summation:
- Automatic Interning: short strings and identifier-like strings (common literals and variable names)
- Non-Interned Strings: longer strings with special characters -- sent to heap
- Explicit Interning: the sys.intern() function can be used to force interning of any string

Expanded Notes:
- CPython has a set of rules and optimizations built into its implementation that dictate which
  strings are automatically interned.
- Some strings are interned at compile time when the bytecode is generated (e.g. def, True, class)
- Certain strings, especially those created frequently during runtime, may be interned dynamically
  based on their usage patterns.

/**********************
  A Callback to Memory
 **********************/

Here's a breakdown of subtleties to the earlier memory layout chart.

Static             | greeting = "Hello, World!"
Static             | def greet():
  String           |    return "Hello!"
Interned           | a = "example"
Interned           | b = "example"  # Uses the same interned string as 'a'
Intern explicitly  | c = sys.intern("interned_string") # sent to heap's internal cache
Dynamic memory     | user_input = input("Enter your name: ")
Dynamic exprs      | welcome_message = "Welcome, " + user_input  # Concatenated at runtime
'''.format(
    num1=num1, num2=num2,
    adr1=id(num1), adr2=id(num2),
    simple_is=demo_literals_with_ids(num1, num2),
    literal_ex1=id(4), literal_ex2=id("asdf"),
            literal_ex3=demo_literals_with_ids(4, 4),
            literal_ex4=demo_literals_with_ids("asdf", "asdf"),
    concat_ex=(demo_literals_with_ids(concatenated_str, "helloworld")),
    interned_ex1=id('c'), interned_ex2=id(d), interned_ex3=(c, d),
    addr_a=id(a), addr_b=id(b), addr_c=id(c), addr_d=id(d)
)

print(memory_layout)
print(literal_ref)
