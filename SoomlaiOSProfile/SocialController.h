/*
 Copyright (C) 2012-2014 Soomla Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import "AuthController.h"
#import "UserProfileUtils.h"

@class Reward;

/**
 A class that loads all social providers and performs social
 actions on with them.  This class wraps the provider's social
 actions in order to connect them to user profile data and rewards.
 
 Inheritance: SocialController > AuthController > ProviderLoader
 */
@interface SocialController : AuthController

/**
 Constructor
 
 Loads all social providers
 */
- (id)init;

/**
 Shares the given status to the user's feed
 
 @param provider the provider to use
 @param status the text to share
 @param reward the reward to grant for sharing
 @exception ProviderNotFoundException if the provider is not supported
 */
- (void)updateStatusWithProvider:(enum Provider)provider andStatus:(NSString *)status andReward:(Reward *)reward;

/**
 Shares a story to the user's feed.  This is very oriented for Facebook.
 
 @param provider The provider to use
 @param message The main text which will appear in the story
 @param name The headline for the link which will be integrated in the
 story
 @param caption The sub-headline for the link which will be
 integrated in the story
 @param description The description for the link which will be
 integrated in the story
 @param link The link which will be integrated into the user's story
 @param picture a Link to a picture which will be featured in the link
 @param reward The reward to give the user
 @exception ProviderNotFoundException if the provider is not supported
 */
- (void)updateStoryWithProvider:(enum Provider)provider
                     andMessage:(NSString *)message
                        andName:(NSString *)name
                     andCaption:(NSString *)caption
                 andDescription:(NSString *)description
                        andLink:(NSString *)link
                     andPicture:(NSString *)picture
                      andReward:(Reward *)reward;

/**
 Shares a photo to the user's feed.  This is very oriented for Facebook.
 
 @param provider The provider to use
 @param message A text that will accompany the image
 @param filePath The desired image's location on the device (full path)
 @param reward The reward to grant for sharing the photo
 @exception ProviderNotFoundException if the provider is not supported
 */
- (void)uploadImageWithProvider:(enum Provider)provider
                     andMessage:(NSString *)message
                    andFilePath:(NSString *)filePath
                      andReward:(Reward *)reward;

/**
 Fetches the user's contact list
 
 @param provider The provider to use
 @param reward The reward to grant
 @exception ProviderNotFoundException if the provider is not supported
 */
- (void)getContactsWith:(enum Provider)provider andReward:(Reward *)reward;

/**
Fetches the user's feed.

@param provider The provider to use
@param reward The reward to grant
@exception ProviderNotFoundException if the provider is not supported
*/
- (void)getFeed:(enum Provider)provider andReward:(Reward *)reward;

/**
 Opens up a page to like for the user (external)
 
 @param provider The provider to like page on
 @param pageName The page to open on the provider
 @param reward The reward to grant when page is liked
 @exception ProviderNotFoundException if the provider is not supported
 */
- (void)like:(enum Provider)provider
            andPageName:(NSString *)pageName
            andReward:(Reward *)reward;

@end
