n = int(input())
books = []
total = 0
for i in range(n):
    book = int(input())
    total += book
    books.append(book)
books.sort(reverse=True)
for i in range(2,len(books), 3):
    total -= books[i]
print(total)