//
//  FLCycleScrollView.h
//  FLCycleScrollView
//
//  Created by lyc on 2017/10/9.
//  Copyright © 2017年 PieDi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "FLBannerSubView.h"


#define Width [UIScreen mainScreen].bounds.size.width

@protocol FLCycleScrollViewDataSource;
@protocol FLCycleScrollViewDelegate;


@interface FLCycleScrollView : UIView<UIScrollViewDelegate>


@property (nonatomic, strong) UIScrollView *scrollView;

@property (nonatomic,assign) BOOL needsReload;
/**
 *  总页数
 */
@property (nonatomic,assign) NSInteger pageCount;

@property (nonatomic,strong) NSMutableArray *cells;
@property (nonatomic,assign) NSRange visibleRange;
/**
 *  如果以后需要支持reuseIdentifier，这边就得使用字典类型了
 */
@property (nonatomic,strong) NSMutableArray *reusableCells;

@property (nonatomic,assign)   id <FLCycleScrollViewDataSource> dataSource;
@property (nonatomic,assign)   id <FLCycleScrollViewDelegate>   delegate;

/**
 *  指示器
 */
@property (nonatomic,strong)  UIPageControl *pageControl;

/**
 *  非当前页的透明比例
 */
@property (nonatomic, assign) CGFloat minimumPageAlpha;

/**
 左右间距,默认20
 */
@property (nonatomic, assign) CGFloat leftRightMargin;

/**
 上下间距,默认30
 */
@property (nonatomic, assign) CGFloat topBottomMargin;

/**
 *  是否开启自动滚动,默认为开启
 */
@property (nonatomic, assign) BOOL isOpenAutoScroll;

/**
 *  是否开启无限轮播,默认为开启
 */
@property (nonatomic, assign) BOOL isCarousel;

/**
 *  当前是第几页
 */
@property (nonatomic, assign, readonly) NSInteger currentPageIndex;

/**
 *  定时器
 */
@property (nonatomic, weak) NSTimer *timer;

/**
 *  自动切换视图的时间,默认是2.0
 */
@property (nonatomic, assign) CGFloat autoTime;

/**
 *  原始页数
 */
@property (nonatomic, assign) NSInteger orginPageCount;

/**
 *  刷新视图
 */
- (void)reloadData;

- (void)registerClass:(nullable Class)cellClass forCellReuseIdentifier:(NSString *)identifier;
/**
 *  获取可重复使用的Cell
 *
 *  @return return value description
 */
- (FLBannerSubView *)dequeueReusableCell:(NSString *)identifier;

/**
 *  滚动到指定的页面
 *
 *  @param pageNumber <#pageNumber description#>
 */
- (void)scrollToPage:(NSUInteger)pageNumber;



/**
 *  关闭定时器,关闭自动滚动
 */
- (void)stopTimer;

@end






@protocol  FLCycleScrollViewDelegate <NSObject>

@optional
/**
 *  当前显示cell的Size(中间页显示大小)
 *
 *  @param flowView flowView description
 *
 *  @return return value description
 */
- (CGSize)sizeForPageInFlowView:(FLCycleScrollView *)flowView;

/**
 *  滚动到了某一列
 *
 *  @param pageNumber pageNumber description
 *  @param flowView   flowView description
 */
- (void)didScrollToPage:(NSInteger)pageNumber inFlowView:(FLCycleScrollView *)flowView;

/*
 *  点击了第几个cell
 *
 *  @param subView 点击的控件
 *  @param subIndex    点击控件的index
 *
 *  @return return value description
 */

- (void)didSelectCell:(FLBannerSubView *)subView withSubViewIndex:(NSInteger)subIndex;

@end


@protocol FLCycleScrollViewDataSource <NSObject>

/**
 *  返回显示View的个数
 *
 *  @param flowView flowView description
 *
 *  @return return value description
 */
- (NSInteger)numberOfPagesInFlowView:(FLCycleScrollView *)flowView;

/**
 *  给某一列设置属性
 *
 *  @param flowView flowView description
 *  @param index    index description
 *
 *  @return return value description
 */
- (FLBannerSubView *)flowView:(FLCycleScrollView *)flowView cellForPageAtIndex:(NSInteger)index;

@end
