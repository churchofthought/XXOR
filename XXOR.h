//
//  XXOR.h
//
//  Created by XibXor on 5/5/13.
//
//  Non-coalescing OR macro for variable arguments and variable types including objects/primitives.
//  Similar to || behavior in ECMAScript
//
//  Usage: OR(a,b,...)
//
//  Examples Below:
//    NSLog(@"%@", OR(nil,@"", @0, @{@"foo": @"bar"}, @[]));
//    // outputs {foo = bar;}
//
//    NSLog(@"%@", OR(nil,@"", @0, @[], @"", [NSNull null]));
//    // outputs <null>
//
//    NSLog(@"%@", OR(nil,[NSNull null], @0, @[], @"foo", @"", @"bar"));
//    // outputs "foo"
//
//    int x = 10;
//    NSLog(@"%f", (float) OR(false, x, 5, 2));
//    // outputs 10.0
//
//    NSLog(@"%s", OR("", "foo", "bar"));
//    // outputs foo
 
#ifndef XIBXOR_OR
 
#define BOOST_PP_VARIADICS 1
#include <boost/preprocessor/seq.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
 
#define __OR(s, state, obj) (isEmpty(obj) ? state : obj)
#define _OR(seq) BOOST_PP_SEQ_FOLD_RIGHT(__OR, BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(seq)),seq), BOOST_PP_SEQ_POP_BACK(seq))
#define OR(...) _OR(BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))
 
 
 
 
/* 
 We define a slew of overloaded isEmpty functions for cases where we know the type at compile-time
 If the type cannot be deduced at compile time, the slower isEmpty(id) is used
 You should cast your id types if you know them for better performance
 */
 
extern inline BOOL isEmpty(const char*         s) { return   !strlen(s); }
extern inline BOOL isEmpty(const long          x) { return           !x; }
extern inline BOOL isEmpty(const int           x) { return           !x; }
extern inline BOOL isEmpty(const short         x) { return           !x; }
extern inline BOOL isEmpty(const char          x) { return           !x; }
extern inline BOOL isEmpty(const double        x) { return           !x; }
extern inline BOOL isEmpty(const float         x) { return           !x; }
extern inline BOOL isEmpty(const NSNumber*     o) { return !o.boolValue; }
extern inline BOOL isEmpty(const NSString*     o) { return    !o.length; }
extern inline BOOL isEmpty(const NSData*       o) { return    !o.length; }
extern inline BOOL isEmpty(const NSSet*        o) { return     !o.count; }
extern inline BOOL isEmpty(const NSArray*      o) { return     !o.count; }
extern inline BOOL isEmpty(const NSDictionary* o) { return     !o.count; }
extern inline BOOL isEmpty(const NSNull*       o) { return          YES; }
extern inline BOOL isEmpty(const id            o) {
    return o == nil
    ||     o == [NSNull null]
    ||   ([o respondsToSelector:@selector(boolValue)]
          && ![o boolValue])
    ||   ([o respondsToSelector:@selector(length)]
          && ![o length])
    ||   ([o respondsToSelector:@selector(count)]
          && ![o count]);
}
 
 
 
#define XIBXOR_OR 1
#endif
