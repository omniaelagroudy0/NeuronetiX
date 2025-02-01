+----------------------+
|        Product       |
+----------------------+
| - name: string       |
| - description: string|
| - price: double      |
| - stockQuantity: int |
+----------------------+
| + getName(): string  |
| + getDescription(): string|
| + getPrice(): double |
| + getStockQuantity(): int|
| + reduceStock(quantity: int): void|
| + increaseStock(quantity: int): void|
| + displayProduct(): void|
+----------------------+

+----------------------+
|         Cart         |
+----------------------+
| - items: CartItem[]  |
| - itemCount: int     |
+----------------------+
| + addItem(product: Product, qty: int): void|
| + removeItem(productName: string): void|
| + updateQuantity(productName: string, qty: int): void|
| + calculateTotal(): double|
| + displayCart(): void     |
| + getItemCount(): int     |
+----------------------+

+----------------------+
|         User         |
+----------------------+
| - userInfo: string   |
| - cart: Cart         |
+----------------------+
| + User(info: string) |
+----------------------+

+----------------------+
|         Order        |
+----------------------+
| - orderSummary: string |
| - paymentStatus: string|
| - shippingDetails: string|
+----------------------+
| + Order(summary: string, payment: string, shipping: string) |
+----------------------+

[Product] <>-- [Cart]
[Cart] o-- [Product]
[User] <>-- [Cart]
[Order] --> [User]
