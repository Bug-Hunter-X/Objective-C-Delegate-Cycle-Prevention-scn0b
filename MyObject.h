**MyObject.h**
```objectivec
#import <Foundation/Foundation.h>

@protocol MyObjectDelegate <NSObject>
- (void)myObjectDidSomething:(MyObject *)object;
@end

@interface MyObject : NSObject
@property (nonatomic, weak) id <MyObjectDelegate> delegate; // Changed to weak

- (void)doSomething;
@end
```

**MyObject.m**
```objectivec
#import "MyObject.h"

@implementation MyObject
- (void)doSomething {
    if (self.delegate) {
        [self.delegate myObjectDidSomething:self];
    }
}
@end
```

**ViewControllerA.m**
```objectivec
#import "ViewControllerA.h"
#import "MyObject.h"

@interface ViewControllerA () <MyObjectDelegate>
@property (nonatomic, strong) MyObject *myObject;
@end

@implementation ViewControllerA
- (void)viewDidLoad {
    [super viewDidLoad];
    self.myObject = [[MyObject alloc] init];
    self.myObject.delegate = self;  // ViewControllerA is now the delegate
    [self.myObject doSomething];
}

- (void)myObjectDidSomething:(MyObject *)object {
    // Handle the event
}
@end
```