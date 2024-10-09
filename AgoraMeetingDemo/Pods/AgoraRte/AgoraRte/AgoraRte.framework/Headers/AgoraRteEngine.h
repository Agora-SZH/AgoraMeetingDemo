//
//  AgoraRte
//
//  Created by Cavan on 2020/11/14.
//

#import <Foundation/Foundation.h>
#import "AgoraRteNetworkTestService.h"
#import "AgoraRteMediaObjectProtocols.h"
#import "AgoraRteObjects.h"
#import "AgoraRteMonitor.h"
#import "AgoraRteScene.h"

NS_ASSUME_NONNULL_BEGIN

// TODO: http 里移除 headers

@protocol AgoraRteEngineDelegate <NSObject>
@optional
- (void)onPeerMessageReceived:(AgoraRteMessage *)message;
- (void)onConnectionStateUpdated:(AgoraRteConnectionState)state;
@end

__attribute__((visibility("default")))
@interface AgoraRteEngine : NSObject
- (instancetype)initWithConfig:(AgoraRteEngineConfig *)config;

- (void)loginWithUserToken:(NSString *)userToken
                   success:(AgoraRteCompletion _Nullable)success
                 failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)logout;

+ (NSString *)getVersion;

- (NSObject<AgoraRteScene> *)createScene:(AgoraRteSceneConfig *)config;

- (NSObject<AgoraRteMediaControl> *)getMediaControl;

- (NSObject<AgoraRteNetworkTestService> *)getNetworkTestService;

- (NSObject<AgoraRteMonitor> *)getMonitor;

- (void)sendPeerMessageWithPayload:(NSDictionary<NSString*, id> *)payload
                               cmd:(NSString *)cmd
                guaranteedDelivery:(BOOL)guaranteedDelivery
                        receiverId:(NSString *)receiverId
                           success:(AgoraRteCompletion _Nullable)success
                           failure:(AgoraRteErrorCompletion _Nullable)failure;

- (void)setParameters:(NSDictionary *)parameters;

- (void)addObserver:(NSObject<AgoraRteEngineDelegate> *)observer;

- (void)removeObserver:(NSObject<AgoraRteEngineDelegate> *)observer;

#pragma mark Unavailable Initializers
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
