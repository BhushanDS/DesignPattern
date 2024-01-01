package com.productservice.productservice.models;


import lombok.Getter;
import lombok.Setter;

@Setter
@Getter
public class Product extends BaseModel{
    private String title;
    private String desc;
    private int price;
    private String image;
    private Category category;


}
