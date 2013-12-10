XXOR
====

 Non-coalescing Objective C++ OR macro for variable arguments and variable types including objects/primitives.

Usage: OR(a,b,...)

Examples Below
====



 
       NSLog(@"%@", OR(nil,@"", @0, @{@"foo": @"bar"}, @[]));
   
   outputs {foo = bar;}
   
----

       NSLog(@"%@", OR(nil,@"", @0, @[], @"", [NSNull null]));
   outputs <null>
    
----  
   
       NSLog(@"%@", OR(nil,[NSNull null], @0, @[], @"foo", @"", @"bar"));
   outputs "foo"
   
----


       int x = 10;
       NSLog(@"%f", (float) OR(false, x, 5, 2));
   outputs 10.0
   
----

       NSLog(@"%s", OR("", "foo", "bar"));
   outputs foo
