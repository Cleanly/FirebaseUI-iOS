//
//  Copyright (c) 2016 Google Inc.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#import "FUIAuth.h"

@class FUIAuthBaseViewController;


/** @typedef FUIEmailHintSignInCallback
    @brief The type of block invoked when an emailHint sign-in event completes.

    @param authResult Optionally; Result of sign-in request containing both the user and
       the additional user info associated with the user.
    @param error Optionally; the error which occurred - or nil if the request was successful.
    @param credential Optionally; The credential used to sign-in.
 */
typedef void (^FUIEmailHintSignInCallback)(FIRAuthDataResult *_Nullable authResult,
                                           NSError *_Nullable error,
                                           FIRAuthCredential *_Nullable credential);

NS_ASSUME_NONNULL_BEGIN



@protocol FUIEmailAuthProvider <NSObject>

- (void)handleAccountLinkingForEmail:(NSString *)email
                       newCredential:(FIRAuthCredential *)newCredential
            presentingViewController:(UIViewController *)presentingViewController
                        signInResult:(_Nullable FIRAuthResultCallback)result;

- (void)signInWithEmailHint:(NSString *)emailHint
   presentingViewController:(FUIAuthBaseViewController *)presentingViewController
              originalError:(NSError *)originalError
                 completion:(FUIEmailHintSignInCallback)completion;

@end

@interface FUIAuth ()

@property(nonatomic, weak) id<FUIEmailAuthProvider> emailAuthProvider;

@end

NS_ASSUME_NONNULL_END
