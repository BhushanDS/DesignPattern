package com.productservice.productservice.services;

import org.springframework.web.bind.annotation.PathVariable;

public interface ProductService {
    String getProductByID(Long id);
    void deleteProductByID( Long id);
    void getAllProducts();
    void createProduct();
    void updateProductByID();

}
