//
//  AgoraRteLocalUser.h
//  AgoraRte
//
//  Created by Cavan on 2023/4/21.
//

#import <Foundation/Foundation.h>
#import "AgoraRteMediaObjectProtocols.h"
#import "AgoraRteObjects.h"
#import "AgoraRteEnums.h"

NS_ASSUME_NONNULL_BEGIN

__attribute__((visibility("default")))
@protocol AgoraRteLocalUser <NSObject>

- (NSString *)getLocalUserId;

// Message
- (void)sendSceneMessage:(NSDictionary<NSString *, id> *)payload
      guaranteedDelivery:(BOOL)guaranteedDelivery
                 success:(AgoraRteCompletion _Nullable)success
                 failure:(AgoraRteErrorCompletion _Nullable)failure;

// Properties
- (void)updateSceneProperties:(NSDictionary<NSString *, id> *)properties
                        cause:(NSDictionary<NSString *, id>  * _Nullable)cause
                      success:(AgoraRteCompletion _Nullable)success
                      failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)deleteSceneProperties:(NSArray<NSString *> *)keyPaths
                        cause:(NSDictionary<NSString *, id>  * _Nullable)cause
                      success:(AgoraRteCompletion _Nullable)success
                      failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)updateUserProperties:(NSDictionary<NSString *, id> *)properties
                       cause:(NSDictionary<NSString *, id>  * _Nullable)cause
                      userId:(NSString *)userId
                     success:(AgoraRteCompletion _Nullable)success
                     failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)deleteUserProperties:(NSArray<NSString *> *)keyPaths
                       cause:(NSDictionary<NSString *, id>  * _Nullable)cause
                      userId:(NSString *)userId
                     success:(AgoraRteCompletion _Nullable)success
                     failure:(AgoraRteErrorCompletion _Nullable)failure;

// Streams
- (void)addStreams:(NSArray<AgoraRteStreamCreateConfig *> *)configs
           success:(AgoraRteCompletion _Nullable)success
           failure:(AgoraRteErrorCompletion _Nullable)failure;

- (AgoraRteError * _Nullable)bindLocalStreams:(NSArray<AgoraRteStreamBindConfig *> *)configs;

- (void)updatePublishPrivilegeOfStreams:(NSDictionary<NSString *, AgoraRteUpdateStreamPrivilege *> *)privileges
                                success:(AgoraRteCompletion _Nullable)success
                                failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)updatePublishPrivilegeOfStreams:(AgoraRteUpdateStreamPrivilege *)privilege
                                  scope:(AgoraRteUpdateStreamPrivilegeScope *)scope
                                success:(AgoraRteCompletion _Nullable)success
                                failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)removeStreams:(NSArray<NSString *> *)streams
              success:(AgoraRteCompletion _Nullable)success
              failure:(AgoraRteErrorCompletion _Nullable)failure;

// Encoder
- (AgoraRteError * _Nullable)setVideoEncoderConfig:(AgoraRteVideoEncoderConfig *)config
                                        streamType:(AgoraRteVideoStreamType)streamType
                                          streamId:(NSString *)streamId;

- (void)prepareToPublishStream:(NSString *)streamId
                         token:(NSString *)token;
- (void)unprepareToPublishStream:(NSString *)streamId;

@end

NS_ASSUME_NONNULL_END
