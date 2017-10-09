//
//  ViewController.m
//  FLCycleScrollView
//
//  Created by lyc on 2017/10/9.
//  Copyright © 2017年 PieDi. All rights reserved.
//

#import "ViewController.h"
#import "FLCycleScrollView.h"



@interface ViewController ()<FLCycleScrollViewDataSource, FLCycleScrollViewDelegate>

/**
 *  图片数组
 */
@property (nonatomic, strong) NSMutableArray *imageArray;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    for (int index = 0; index < 5; index++) {
        UIImage *image = [UIImage imageNamed:[NSString stringWithFormat:@"Yosemite%02d",index]];
        [self.imageArray addObject:image];
    }
    
    [self setupUI];
}


- (void)setupUI {
    
//    self.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
    
    FLCycleScrollView *pageFlowView = [[FLCycleScrollView alloc] initWithFrame:CGRectMake(0, 72, Width, Width * 9 / 16)];
    [pageFlowView registerClass:[FLBannerSubView class] forCellReuseIdentifier:@"FLBannerSubView"];
    pageFlowView.delegate = self;
    pageFlowView.dataSource = self;
    pageFlowView.minimumPageAlpha = 0.1;
    
    

    [pageFlowView reloadData];
    
    [self.view addSubview:pageFlowView];
    

    
}


#pragma mark Delegate
- (CGSize)sizeForPageInFlowView:(FLCycleScrollView *)flowView {
    return CGSizeMake(Width - 60, (Width - 60) * 9 / 16);
}

- (void)didSelectCell:(FLBannerSubView *)subView withSubViewIndex:(NSInteger)subIndex {
    
    NSLog(@"点击了第%ld张图",(long)subIndex + 1);
    
    
}

- (void)didScrollToPage:(NSInteger)pageNumber inFlowView:(FLCycleScrollView *)flowView {
    
    NSLog(@"ViewController 滚动到了第%ld页",pageNumber);
}

#pragma mark  Datasource
- (NSInteger)numberOfPagesInFlowView:(FLCycleScrollView *)flowView {
    
    return self.imageArray.count;
    
}

- (FLBannerSubView *)flowView:(FLCycleScrollView *)flowView cellForPageAtIndex:(NSInteger)index{
    FLBannerSubView *bannerView = [flowView dequeueReusableCell:@"FLBannerSubView"];
    if (!bannerView) {
        bannerView = [[FLBannerSubView alloc] init];
        bannerView.tag = index;
        bannerView.layer.cornerRadius = 4;
        bannerView.layer.masksToBounds = YES;
    }
    //在这里下载网络图片
    //  [bannerView.mainImageView sd_setImageWithURL:[NSURL URLWithString:[NSString stringWithFormat:hostUrlsImg,imageDict[@"img"]]] placeholderImage:[UIImage imageNamed:@""]];
    bannerView.mainImageView.image = self.imageArray[index];
    
    return bannerView;
}


#pragma mark --懒加载
- (NSMutableArray *)imageArray {
    if (_imageArray == nil) {
        _imageArray = [NSMutableArray array];
    }
    return _imageArray;
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
