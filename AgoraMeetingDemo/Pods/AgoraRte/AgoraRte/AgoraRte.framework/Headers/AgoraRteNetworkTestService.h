//
//  AgoraRteNetworkTestService.h
//  AgoraRte
//
//  Created by Cavan on 2023/4/20.
//

#import <Foundation/Foundation.h>
#import "AgoraRteObjects.h"
#import "AgoraRteEnums.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AgoraRteNetworkTestService;
@protocol AgoraRteNetworkTestDelegate <NSObject>
- (void)networkTestService:(NSObject<AgoraRteNetworkTestService> *)service
           lastmileQuality:(AgoraRteNetworkQuality)quality;
@end

__attribute__((visibility("default")))
@protocol AgoraRteNetworkTestService <NSObject>
@property (nonatomic, weak) id<AgoraRteNetworkTestDelegate> delegate;

- (AgoraRteError * _Nullable)startLastmileProbeTest:(AgoraRteLastmileProbeConfig * _Nullable)config;
- (AgoraRteError * _Nullable)stopLastmileProbeTest;
@end

NS_ASSUME_NONNULL_END
