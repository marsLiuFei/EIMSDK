//
//  EIMGroup.h
//  EIMSDK
//
//  Created by duanjiahuan on 2020/10/14.
//  Copyright © 2020 duanjiahuan. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, EIMGroupStyle) {
    //普通群
    EIMGroupStyleNormal = 1,
    //组织内部群
    EIMGroupStyleOrgAttach,
    //组织节点群
    EIMGroupStyleOrgNode,
};

NS_ASSUME_NONNULL_BEGIN

@interface EIMGroup : NSObject

#pragma mark - DB

/*
*  MARK:群的id
*/
@property (nonatomic, copy) NSString *groupId;

/*
*  MARK:群名称
*/
@property (nonatomic, copy) NSString *groupName;

/*
*  MARK:是否社区经理群
*/
@property (nonatomic, strong) NSNumber *isOfficial;

#pragma mark - more

@end

NS_ASSUME_NONNULL_END
