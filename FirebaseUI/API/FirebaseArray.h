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

#import <Foundation/Foundation.h>

@class Firebase;

@protocol FirebaseArrayDelegate;

@interface FirebaseArray : NSObject

@property (weak, nonatomic) id<FirebaseArrayDelegate> delegate;

@property (strong, nonatomic) Firebase *ref;
@property (strong, nonatomic) NSMutableArray *snapshots;

#pragma mark -
#pragma mark Initializer methods

- (instancetype)initWithRef:(Firebase *)ref;
- (instancetype)initWithQuery:(Firebase *)ref;

#pragma mark -
#pragma mark Public API methods

- (NSUInteger)count;
- (id)objectAtIndex:(NSUInteger)index;
- (Firebase *)refForIndex:(NSUInteger)index;

#pragma mark -
#pragma mark Private API methods

- (NSUInteger)indexForKey:(NSString *)key;

@end

@protocol FirebaseArrayDelegate <NSObject>

@optional
- (void) childAdded:(id)obj atIndex:(NSUInteger)index;
- (void) childChanged:(id)obj atIndex:(NSUInteger)index;
- (void) childMoved:(id)obj fromIndex:(NSUInteger)fromIndex toIndex:(NSUInteger)toIndex;
- (void) childRemoved:(id)obj atIndex:(NSUInteger)index;

@end