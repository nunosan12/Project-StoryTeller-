//
//  Home.cpp
//  storyTeller
//
//  Created by vantan on 2016/05/02.
//
//

#include "Home.hpp"

USING_NS_CC;

Scene* Home::CreateScene()
{
    Scene* scene = Scene::create();
    Layer* layer = Home::create();
    
    scene->addChild(layer);
    return  scene;
}

bool Home::init()
{
    if(!Layer::init()){ return false; }
    
//    Director* director = Director::getInstance();
//    Size size = director->getWinSize();
    
    SetUiImage();
    
    return true;
}

void Home::SetUiImage()
{
    auto filePath = FileUtils::getInstance()->fullPathForFilename("DataFile/HomeImagePath.txt");
    std::ifstream inFile(filePath);
    assert(inFile);
    
    size_t imageValue;
    std::string _imagePath;
    Vec2 pos, size;
    
    inFile >> imageValue;
    Sprite* bgSprite[imageValue];
    for(int i = 0; i < imageValue; i++)
    {
        inFile >> _imagePath >> pos.x >> pos.y >> size.x >> size.y;
        
        bgSprite[i] = Sprite::create(_imagePath);
        bgSprite[i]->setPosition(Vec2(pos.x, pos.y));
        bgSprite[i]->setScale(size.x, size.y);
        this->addChild(bgSprite[i]);
    }
}