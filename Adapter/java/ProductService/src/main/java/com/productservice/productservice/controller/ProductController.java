package com.productservice.productservice.controller;

import com.productservice.productservice.services.FakeStoreProductService;
import com.productservice.productservice.services.ProductService;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.web.bind.annotation.*;

@RestController  // This is the way to tell controller create the product at time of starting
@RequestMapping("/products")
public class ProductController {

    private ProductService productService;

    //constructor injection

    ProductController(@Qualifier("fakeStoreProductService") ProductService productService)
    {
        this.productService = productService;
    }

    @GetMapping("/{id}")
    public String getProductByID(@PathVariable("id") Long id)
    {
        return productService.getProductByID(id);
    }

    @GetMapping
    public void getAllProducts()
    {


    }

    @DeleteMapping ("{id}")
    public void deleteProductByID(@PathVariable("id") Long id)
    {

    }

    public void createProduct()
    {

    }


    public void updateProductByID()
    {

    }
}
