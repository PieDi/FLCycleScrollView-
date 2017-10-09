//
//  FLBannerSubView.h
//  FLCycleScrollView
//
//  Created by lyc on 2017/10/9.
//  Copyright © 2017年 PieDi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface FLBannerSubView : UIView

/**
 *  主图
 */
@property (nonatomic, strong) UIImageView *mainImageView;

/**
 *  用来变色的view
 */
@property (nonatomic, strong) UIView *coverView;

@property (nonatomic, copy) void (^didSelectCellBlock)(NSInteger tag, FLBannerSubView *cell);

@property (nonatomic, strong) NSString *identifier; // 重用标识符
/**
 设置子控件frame,继承后要重写
 
 @param superViewBounds superViewBounds description
 */
- (void)setSubviewsWithSuperViewBounds:(CGRect)superViewBounds;

@end
