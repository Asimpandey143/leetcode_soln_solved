class ProductOfNumbers {
private:
    vector<int> prefix = {1};

public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) {
            prefix = {1};
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        if (k >= prefix.size()) {
            return 0;
        }
        return prefix.back() / prefix[prefix.size() - 1 - k];
    }
};