# Performance-Monitor-Project
Là 1 Project dùng ChatGPT để Generate đoạn code về Biểu đồ thông số CPU và RAM bằng ngôn ngữ C++ với IDE Code::Blocks, cùng với thư viện SFML và Windows Performance Counter (Vui lòng đọc để tham khảo!)

# Cách sử dụng:
1. Tải IDE Code::Blocks hoặc Visual Studio Code (VS Code for short)
2. Vào Code::Blocks và sau đó thêm Project này (Tất nhiên là anh bạn phải tải về, không tải về chắc tới mai cũng chưa cài xong)
3. Nhấn vào chữ "Project" bên trên góc trái, sau đó bấm vào "Build Option"
4. Sau khi nhấn vào, sẽ hiện lên 1 Cửa Sổ mới, bấm vào Search Directories
5. Thêm đường dẫn đến thư mục "include" của SFML (SFML khá khó cài nên có thể sẽ mất thời gian để cài, phiên bản thằng tạo ra đang dùng là phiên bản SFML-2.5.1 (khúc đằng sau người tạo chịu)
6. Sau khi thêm đường dẫn, cần thêm thư mục "lib". Tại cửa sổ "Complier" nhìn sang bên phải 1 xíu sẽ thấy chữ "Linker" kế bên "Complier", nhấp vào đó
7. Thêm đường dẫn đến thư mục "lib" của SFML
8. Sau khi thêm xong, nhìn lên trên và quay về cửa sổ "Linker Settings"
9. Thêm những tệp trong thư mục "lib" của SFML (Trừ thư mục trong đó ra) (Thêm 1 điều nữa, khi tải xong và bật lên bạn sẽ thấy nó được thêm hết rồi, nhưng đừng vội vàng, hãy xóa hết đi cả cái include và lib nữa, đường dẫn đó chỉ tương thích với máy của người làm ra thôi)
10. Sau đó, thêm những đường dẫn sau đây:
    + psapi.dll
    + Performance Data Helper (chắc cũng không cần dùng tới)
    + Windows Performance Counter (chắc cũng không cần dùng tới)
11. Sau khi add xong, bấm OK và quay lại File Explorer
12. Copy tất cả các tệp như trong hình từ thư mục "bin" của SFML:
![image](https://github.com/IamsadVN/Performance-Monitor-Project/assets/112055678/3b3b11b5-f29c-4d95-b925-41b83908dd1a)
13. Vào thư mục Project
14. Vào thư mục "bin" và vào thư mục "Debug"
15. Sau đó, thêm các thứ cần thiết cho Project từ SFML như ở trên hình kia:
![image](https://github.com/IamsadVN/Performance-Monitor-Project/assets/112055678/7d47b5a3-50b4-4fda-be4e-7de69e4c6eca)
16. Cuối cùng, kiểm tra lại xem đã làm đủ các bước chưa, sau đó bấm chạy là hoàn thành
