# Retain Cycle in Objective-C Delegate Pattern

This repository demonstrates a common Objective-C memory management issue: retain cycles in delegate patterns.  A view controller sets itself as the delegate of another object, creating a circular strong reference that prevents deallocation and leads to memory leaks.

## Problem

The `ViewControllerA` class sets itself as the delegate of `MyObject`.  Both objects hold strong references to each other, resulting in a retain cycle.  Even when `ViewControllerA` is dismissed, neither object is deallocated because they are mutually referencing each other.

## Solution

The solution involves using `weak` references to break the retain cycle.  `MyObject` should declare its delegate property as `weak`, preventing it from retaining `ViewControllerA`. This allows `ViewControllerA` to be deallocated normally when it's no longer needed. 