// clang-format off

/*
 * Firebase UI Bindings iOS Library
 *
 * Copyright © 2015 Firebase - All Rights Reserved
 * https://www.firebase.com
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binaryform must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY FIREBASE AS IS AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL FIREBASE BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// clang-format on

#import <Firebase/Firebase.h>

#import "FirebaseDataSource.h"

@interface FirebaseDataSource ()
@property(copy, nonatomic) void (^cancelBlock)(NSError *);
@end

@implementation FirebaseDataSource

#pragma mark -
#pragma mark Initializer methods

- (instancetype)initWithArray:(FirebaseArray *)array {
  self = [super init];
  if (self) {
    self.array = array;
    self.array.delegate = self;
  }
  return self;
}

#pragma mark -
#pragma mark API methods

- (NSUInteger)count {
  return [self.array count];
}

- (id)objectAtIndex:(NSUInteger)index {
  return [self.array objectAtIndex:index];
}

- (Firebase *)refForIndex:(NSUInteger)index {
  return [self.array refForIndex:index];
}

- (void)cancelWithBlock:(void (^)(NSError *))block {
  self.cancelBlock = block;
}

#pragma mark -
#pragma mark FirebaseArrayDelegate methods

- (void)canceledWithError:(NSError *)error {
  if (self.cancelBlock != nil) {
    self.cancelBlock(error);
  }
}

@end
