package com.productservice.productservice.services;

import org.springframework.stereotype.Service;

@Service("fakeStoreProductService")
public class FakeStoreProductService  implements ProductService{
    @Override
    public String getProductByID(Long id) {
        return "returning id:" + id;
    }

    @Override
    public void deleteProductByID(Long id) {

    }

    @Override
    public void getAllProducts() {

    }

    @Override
    public void createProduct() {

    }

    @Override
    public void updateProductByID() {

    }
}
