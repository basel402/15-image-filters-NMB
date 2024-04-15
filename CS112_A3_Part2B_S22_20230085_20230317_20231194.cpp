
#include <iostream>
using namespace std;
#include "Image_Class.h"


/*

Basel mohamed abd elmoneim mohamed holaiel: did filters 1,4,7,10,17,menu of the program. id:20230085
mohamed ahmed mohamed mostafa elkady: did filters 2,5,8,11,16, id: 20230317
Nourhan ahmed hussien: did filters 3,6,9,12,13 , id: 202301194

*/


void invert() {
    cout << "\n############################## Welcome to invert image filter ##########################################\n";
    string file_name;
    cout << "please enter the name of the image: ";
    cin >> file_name;
    string saved_file;
    Image image(file_name) ;

    for (int i = 0 ; i < image.width ; i++){
        for(int j = 0 ; j < image.height ; j++ ){


            for(int k = 0 ; k < 3 ; k++){

                image(i , j ,k ) = 255 -  image(i , j ,k );

            }

        }
    }

    cout << "please enter an image name to store a new image\n";
    cout << "and specify your desired extension: .jpg, .bmp, .png, .tga: ";
    cin >> saved_file;
    image.saveImage(saved_file);
    cout << "Done" << endl << endl;;
    
}

void flip() {
    string choice;
    string filename;
    cout << "\n######################### Welcome to flip image filter ##############################\n";
    cout << "please choose 1 or 2: \n";
    cout << "1. Flip horizontally\n";
    cout << "2. Flip vertically\n";
    cin >>choice;
    
        if (choice == "1") {
            cout << "Pls enter an image name to flip it: ";
            cin >> filename;
            Image image(filename);
            for (int x = 0; x < image.width / 2; ++x) {
                for (int y = 0; y < image.height; ++y) {
                    for (int z = 0; z < 3; ++z) {

                        unsigned int temp = image(x,y,z);
                        image(x, y, z) = image(image.width - x - 1, y, z);
                        image(image.width - x - 1, y, z) = temp;
                    }
                }
            }
           cout << "please enter an image name to store a new image\n";
    cout << "and specify your desired extension: .jpg, .bmp, .png, .tga: ";
            cin >> filename;
            image.saveImage(filename);
            
        }

        else if(choice =="2"){
            cout << "Pls enter an image name to flip it: ";
            cin >> filename;
            Image image(filename);
            for (int x = 0; x < image.width; ++x) {
                for (int y = 0; y < image.height / 2; ++y) {
                    for (int z = 0; z < 3; ++z) {
                        unsigned int temp = image(x,y,z);
                        image(x, y, z) = image(x, image.height - y - 1, z);
                        image(x, image.height - y - 1, z) = temp;
                    }
                }
            }
            cout << "please enter an image name to store a new image\n";
    cout << "and specify your desired extension: .jpg, .bmp, .png, .tga: ";
            cin >> filename;
            image.saveImage(filename);
            
        }

    cout << "Done" << endl << endl;;


}

void BW() {
    string filename;
    cout << "\n########################### Welcome to black and white filter ################################\n";
    cout << "Pls enter colored image name to turn to black and white: ";
    cin >> filename;

    Image image(filename);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }

            avg /= 3;
            if (avg>127){
                avg=255;
            }
            else {
                avg = 0;
            }
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
    cout << "please enter an image name to store a new image\n";
    cout << "and specify your desired extension: .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
    cout << "Done" << endl;
    
}

void darken_lighten(){
    cout << "\n##################### Welcome to darken_lighten filter #######################\n";
    Image img1;
    string text,choose;
    cout << "1)Darken the image\n2)Lighten the image\n";
    cout << "enter the number of your desired choice: ";
    cin >> choose;
    while(choose!="1" && choose!="2"){
        cout << "error enter a number between 1 and 2: ";
        cin >> choose;
    }
    cout << "please enter the name of the image: ";
    cin >> text;
    img1.loadNewImage(text);
    for(int i = 0; i<img1.width;i++){

        for(int j = 0; j<img1.height;j++){
int sum = 200,avg=0;
            for(int k =0 ; k<img1.channels ;k++){

                if(choose=="1"){
                    img1(i,j,k)-=(img1(i,j,k)/2);
                }
                
                else{
                    avg+=img1(i,j,k);
                    
                }
            }
            if(choose=="2"){
                 
                    img1(i,j,0)= min((img1(i,j,0)/2+img1(i,j,0)),255);
                    img1(i,j,1)= min((img1(i,j,1)/2+img1(i,j,1)),255);
                    img1(i,j,2)= min((img1(i,j,2)/2+img1(i,j,2)),255);
                
            
            }

        }
    }
    cout << "please enter an image name to store a new image\n";
    cout << "and specify your desired extension: .jpg, .bmp, .png, .tga: ";
    cin >> text;
img1.saveImage(text);
    cout << "Done" << endl << endl;;

}

void Grayscale_conversion(){
cout << "\n########################## Welcome to Grayscale_conversion filter ##################################\n";
cout << "Please enter the name of the image: ";
string filename;
cin >> filename;
Image img(filename);

for(int i = 0 ; i<img.width ; i++){
    
    for(int j = 0 ; j<img.height ; j++){

        unsigned int average = 0;
        for(int k = 0 ; k<img.channels; k++){

            average+=img(i,j,k);

        }

        average/=3;
        img(i,j,0)=average;
        img(i,j,1)=average;
        img(i,j,2)=average;       
       
    }
   

}
 cout << "please enter an image name to store a new image\n";
    cout << "and specify your desired extension: .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    img.saveImage(filename);
    cout << "Done" << endl << endl;;
    
}

void edge(){

    Image img;
    string filename;
    cout << "\n##################### Welcome to edge filter #########################\n";
    cout << "please enter the image name: ";
    cin >> filename;
    img.loadNewImage(filename);
    Image new_image(img.width,img.height);
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            unsigned  int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += img(i, j, k);
            }

            avg /= 3;
            if (avg>127){
                avg=255;
            }
            else {
                avg = 0;
            }
            img(i, j, 0) = avg;
            img(i, j, 1) = avg;
            img(i, j, 2) = avg;
        }
    }

    
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {
            
            if(j==img.height-1 || i==img.width-1)break;
            for (int k = 0; k < 3; ++k) {
                if(img(i,j,k)!=img(i,j+1,k))new_image(i,j,k)=0;
                else if(img(i,j,k)!=img(i+1,j,k))new_image(i,j,k)=0;
                else{
                    new_image(i,j,k)=255;
                }
            }

            
        }
    }
    
    
    cout << "please enter an image name to store a new image\n";
    cout << "and specify your desired extension: .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    new_image.saveImage(filename);
    cout << "Done" << endl << endl;

    
}

void infrared(){
    string file_name;
    cout << "\n###################### Welcome to infrared filter ##############################\n";
    cout << "please enter the image name: ";
    cin >> file_name; 
    Image image(file_name) ;

    for (int i = 0 ; i < image.width ; i++){
        for(int j = 0 ; j < image.height ; j++ ){


            for(int k = 0 ; k < 3 ; k++){

                image(i , j ,k ) = 255 -  image(i , j ,k );

            }
            

        }
    }

    for(int i = 0 ; i<image.width;i++){

        for(int j = 0 ; j<image.height;j++){
            
                image(i,j,0)=255;
                
        }

    }
    cout << "please enter an image name to store a new image\n";
    cout << "and specify your desired extension: .jpg, .bmp, .png, .tga: ";
    cin >> file_name;
    image.saveImage(file_name);
    cout << "Done" << endl << endl;

}

void rotate_270(){
string file_name;
cout << "please enter image name: ";
cin >> file_name;
    Image image(file_name) ,rotated_image(image.height,image.width);
    string saved_file;
    for (int i = 0 ; i < image.width ; i++){
        for(int j = 0 ; j < image.height ; j++ ){


            for (int k = 0 ; k < 3 ; k++){
                rotated_image(j, i ,k ) = image(i,j ,k);
            }

        }
    }
    cout << "enter the name of file to save the image : ";
    cin >> saved_file;
    rotated_image.saveImage(saved_file);

}

void rotate_180(){
string file_name;
cout << "please enter image name: ";
cin>> file_name;
    Image image( file_name) ,rotated_image(image.width , image.height);
    string saved_file;

    for (int i = 0 ; i < image.width ; i++){
        for(int j = 0  ; j <image.height  ; j++ ){


            for (int k = 0 ; k < 3 ; k++){
                rotated_image(i, j ,k ) = image(  image.width - 1 - i  ,  image.height - 1 - j  ,k);
            }

        }
    }
    cout << "enter the name of file to save the image : ";
    cin >> saved_file;
    rotated_image.saveImage(saved_file);

}

void rotate_90() {
    string file_name;
    cout << "\n################################ Welcome to rotate filter ##################################\n";
    int choice;
    cout << "1) rotate 90\n2) rotate 180\n3) rotate 270\n";
    cout << "enter a number between 1 and 3: ";
    cin >> choice;
    if(choice==2)rotate_180();
    else if(choice==3)rotate_270();
    else{
    cout << "please enter image name: ";
cin>> file_name;
    string saved_file;

    Image image(file_name) , rotated_image(image.height , image.width  );

    for (int i = 0 ; i < image.width ; i++){
        for(int j = 0  ; j <image.height  ; j++ ){


            for (int k = 0 ; k < 3 ; k++){
                rotated_image(image.height  - 1 - j,  i ,k ) = image( i,  j  ,k);

            }

        }
    }
    cout << "enter the name of file to save the image : ";
    cin >> saved_file;
    rotated_image.saveImage(saved_file);
    }
}

Image size_merge(Image img,double width,double height){
   
    Image new_img(width,height);
     
    double row = img.width/width , col = img.height/height;

        for(int i = 0; i<width ;i++){
                 
            for(int j =0 ; j<height ;j++){
                         
                for(int k = 0 ; k<3;k++){

                    new_img(i,j,k)=img(round(i*row),round(j*col),k);

                }   
                    
            }
            
        }
        
        return new_img;
}

void Blur_filter() {
    cout << "\n####################### Welcome to blur filter #############################\n";
    string filename;
    cout << "please enter the name of the image: " << endl ;
    cin >> filename;
    Image image(filename);
    Image blurred_image(image.width, image.height);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int Red = 0, Green = 0, Blue = 0;
            int counter = 0;

            for (int n = -14; n <= 14; ++n) {
                for (int m = -14; m <= 14; ++m) {
                    int sum1 = i + n;
                    int sum2 = j + m;


                    if (sum1 >= 0 && sum1 < image.width && sum2 >= 0 && sum2 < image.height) {
                        Red += image(sum1, sum2, 0);
                        Green += image(sum1, sum2, 1);
                        Blue += image(sum1, sum2, 2);
                        counter++;
                    }
                }
            }

            blurred_image(i, j, 0) = Red / counter;
            blurred_image(i, j, 1) = Green / counter;
            blurred_image(i, j, 2) = Blue / counter;
        }
    }

    image = blurred_image;
    
    string saved_file;
    
    cout << " plz enter the name of file to save the image : ";
    cin >> saved_file;
    image.saveImage(saved_file);
    cout<<"Done";

}

void merge(){

    Image img1,img2;
    string filename;
    cout << "\n######################## Welcome to merge filter #############################\n";
    cout << "please enter the name of the first image: ";
    cin >> filename;
    img1.loadNewImage(filename);
    cout << "please enter the name of the second image: ";
    cin >> filename;
    img2.loadNewImage(filename);
    int choice;
    cout << "1)resize the 2 images to the max dimensions and merge\n2)merge on the common area\n";
    cout << "enter a choice between 1 and 2: ";
    cin >> choice;
    double width,height;
    
    
        choice==1?width = max(img1.width,img2.width):width = min(img1.width,img2.width),choice==1?height = max(img1.height,img2.height):height = min(img1.height,img2.height);
       if(choice==1){
         img1 = size_merge(img1,width,height);
         img2 = size_merge(img2,width,height);
       }
        Image img3(width,height); 
    
        
        
    
    

        for(int i = 0 ; i<width ; i++){

                for(int j = 0 ; j<height;j++){

                        for(int k = 0 ; k<3 ;k++){

                           img3(i,j,k) = (img1(i,j,k)+img2(i,j,k))/2;
                                
                        }
                        

                }
        }
    cout << "please enter an image name to store a new image\n";
    cout << "and specify your desired extension: .jpg, .bmp, .png, .tga: ";
    cin >> filename;
    img3.saveImage(filename);
    cout << "Done" << endl << endl;;
}

void purple_filter(){
    cout << "\n#################### Welcome to purple filter #######################\n";
    string filename;
    cout <<"please enter your image :";
    cin >> filename;
    Image image(filename);

    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            unsigned char& greenValue = image(x, y, 1);
            greenValue = greenValue * 0.7;
        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
    cout << "Image modified and saved as: " << filename << endl;

}

Image resizeImage(Image img,double width,double height){
    
    Image new_img(width,height);

    double row = img.width/width , col = img.height/height;

    for(int i = 0; i<width ;i++){

        for(int j =0 ; j<height ;j++){

            for(int k = 0 ; k<3;k++){

                new_img(i,j,k)=img(round(i*row),round(j*col),k);

            }

        }

    }

    return new_img;
}

void resize_image_filter(){
    cout << "\n######################### Welcome to resize_image_filter ############################\n";
    string filename;
    double new_width, new_height;

    cout <<"please enter the image you want to resize:";
    cin >> filename;
    Image image(filename);

    cout << "Enter the desired new width:";
    cin >> new_width;
    cout << "Enter the desired new height:";
    cin >> new_height;

    Image resizedImage(new_width, new_height);
    resizedImage = resizeImage(image, new_width, new_height);
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    resizedImage.saveImage(filename);
    cout << "Image resized successfully and saved as: " << filename << endl;

}

Image cropImage( Image& originalImage, int x, int y, int width, int height, string outputFilename) {

    int croppedWidth = min(width, originalImage.width - x);
    int croppedHeight = min(height, originalImage.height - y);
    Image croppedImage(croppedWidth, croppedHeight);
    for (int row = 0; row < croppedHeight; row++) {
        for (int col = 0; col < croppedWidth; col++) {
            for (int channel = 0; channel < originalImage.channels; channel++) {
                croppedImage(row, col, channel) = originalImage(y + row, x + col, channel);
            }
        }
    }
    return croppedImage;
}

void crop_image_filter(){
    cout << "\n######################## Welcome to crop_image_filter ########################\n";
    string filename;
    int x, y, width, height;
    cout <<"please enter the image you want to crop:";
    cin >> filename;
    Image image(filename);
    cout << "Enter x-coordinate of top-left corner:";
    cin >> x;
    cout << "Enter y-coordinate of top-left corner:";
    cin >> y;
    cout << "Enter width of the crop area:";
    cin >> width;
    cout << "Enter height of the crop area:";
    cin >> height;

    Image croppedImage;

    croppedImage = cropImage(image, x, y, width, height, filename);

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    croppedImage.saveImage(filename);
    cout << "Image cropped successfully and saved as: " << filename << endl;
}

void sunlight()
{
    cout << "\n####################### Welcome to sunlight filter ###########################\n";
    cout << " please enter the name of the image: ";    
    string filename;
    cin >> filename;
    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {


            image(i, j, 0) *= 0.89;
            image(i, j, 1) *= 0.89 ;
            image(i, j, 2) *= 0.3;
        }
    }

    cout << "plz enter the name of file to save the image " << endl ;
    string saved_file;
    cin >> saved_file;
    image.saveImage(saved_file);
    cout << "Done"<<endl;


}

void fancy_frame() {


    cout << " please enter the name of image file: " ;
    string filename;
    cin >> filename;
    Image image(filename);

    //upper frame
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < image.width; j++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = 255;

            }

        }
    }

    for (int i = 0; i < image.height; i++) {
        for (int j = 0; j < 20; j++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = 255;

            }

        }
    }
    for (int i = image.height - 20; i < image.height; i++) {
        for (int j = 0; j < image.width; j++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = 255;

            }

        }
    }

    for (int i = 0; i < image.height; i++) {
        for (int j = image.width - 20; j < image.width; j++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = 255;

            }
        }
    }


    //upper frame
    for (int i = 40; i < 50; i++) {
        for (int j = 40; j < image.width - 40; j++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = 255;

            }


        }
    }
    //left frame
    for (int i = 40; i < image.height - 40; i++) {
        for (int j = 40; j < 50; j++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = 255;

            }

        }
    }
    //lower frame
    for (int i = image.height - 50; i < image.height - 40; i++) {
        for (int j = 40; j < image.width - 40; j++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = 255;

            }
        }
    }

    //right frame
    for (int i = 40; i < image.height - 40; i++) {
        for (int j = image.width - 50; j < image.width - 40; j++) {
            for (int k = 0; k < 3; k++) {
                image(j, i, k) = 255;

            }

        }
    }


    // Draw hollow squares in each corner

    //top right corner
    for (int i = 0 ; i < 70; i++) {
        for (int j = image.width - 70; j < image.width; j++) {
            for (int k = 0; k < 3; k++) {
                // Set white border     //if (i < 10 || i >= 60 || (j >= image.width - 10 && j < image.width) || (j >= image.width - 60 && j < image.width - 50))
                if ((i >= 60 && j <= image.width)  || ( i <= 60 && j <= image.width-60) )
                {
                    image(j, i, k) = 255;
                }
            }
        }
    }

    // Top left corner
    for (int i = 0; i < 70; i++) {
        for (int j = 0; j < 70; j++) {
            for (int k = 0; k < 3; k++) {
                // Set white border
                if ( i >= 60  || j >= 60) {
                    image(j, i, k) = 255;
                }

            }
        }
    }

    // Bottom left corner
    for (int i = image.height - 70; i < image.height; i++) {
        for (int j = 0; j < 70; j++) {
            for (int k = 0; k < 3; k++) {
                // Set white border
                if ((i <= image.height - 60) ||  j >= 60) {
                    image(j, i, k) = 255;
                }

            }
        }
    }

    // Bottom right corner
    for (int i = image.height - 70; i < image.height; i++) {
        for (int j = image.width - 70; j < image.width; j++) {
            for (int k = 0; k < 3; k++) {
                // Set white border
                if ((i <= image.height - 60 &&  j < image.width) || (i >= image.height - 60 && j <= image.width - 60) )  {
                    image(j, i, k) = 255;
                }

            }
        }
    }

    string saved_file;
    cout << " plz enter the name of file to save the image : ";
    cin >> saved_file;
    image.saveImage(saved_file);
    cout <<"Done";

}

void simple_frame(){

    cout << "\n################### Welcome to frame filter ######################\n";
    int choice;
    cout << "1) simple frame\n2) fancy frame\n";
    cout << "enter a number between 1 and 2: ";
    cin >> choice;
    if(choice==2)fancy_frame();
    else{
    cout << " plz enter the name of image file " << endl ;
    string filename;
    cin >> filename;
    Image image(filename);

    int choice ,red , green, blue ;
    cout << "choose the color of the frame " << endl << "1)Red \n2)Green \n3)Blue \n4)White \n5)Black \n6)Yellow \n";

    cin >> choice;

    while(choice < 1 || choice > 6 ){
        cout << "please enter a number from 1 to 6 : " << endl ;
        cin >> choice;
    }

    if (choice == 1){
        red = 255;
        green = 0;
        blue = 0;
    }

    else if (choice == 2){
        red = 0;
        green = 255 ;
        blue = 0 ;
    }
    else if (choice == 3){
        red = 0;
        green = 0 ;
        blue = 255 ;
    }
    else if (choice == 4){
        red = 255;
        green = 255 ;
        blue = 255 ;
    }
    else if (choice == 5){
        red = 0;
        green = 0 ;
        blue = 0 ;
    }
    else if (choice == 6){
        red = 255;
        green = 255 ;
        blue = 0 ;
    }


    //upper frame
    for (int i = 0 ; i < 20  ; i++){
        for(int j = 0 ; j < image.width  ; j++ ){

            image(j, i ,0 ) = red ;
            image(j, i ,1 ) = green;
            image(j, i ,2 ) = blue ;

        }
    }

    for (int i = 0 ; i < image.height  ; i++){
        for(int j = 0 ; j < 20  ; j++ ){

            image(j, i ,0 ) = red ;
            image(j, i ,1 ) = green;
            image(j, i ,2 ) = blue ;

        }
    }
    for (int i = image.height -20  ; i < image.height ; i++){
        for(int j = 0 ; j < image.width  ; j++ ){

            image(j, i ,0 ) = red ;
            image(j, i ,1 ) = green;
            image(j, i ,2 ) = blue ;

        }
    }

    for (int i = 0  ; i < image.height ; i++){
        for(int j = image.width - 20 ; j < image.width  ; j++ ){

            image(j, i ,0 ) = red ;
            image(j, i ,1 ) = green;
            image(j, i ,2 ) = blue ;

        }
    }
    string saved_file;
    cout << " plz enter the name of file to save the image : ";
    cin >> saved_file;
    image.saveImage(saved_file);
    cout<<"Done";
    }

}

void menu(){
    cout << "\n############################### Welcome to the main program ###############################\n\n";
    cout <<"1) Grayscale conversion\n2) Black and White\n3) Invert image\n4) Merge image\n5) Flip image\n6) Rotate image\n";
    cout << "7) Darken and Lighten image\n8) Crop image\n9) Adding a Frame to the picture\n10) Detect image edges\n11) Resizing image\n";
    cout << "12) Blur images\n13) Sunlight filter\n14) Purple Filter\n15) Infrared filter\n16) Exit the program\n";
    cout << "Please enter a number between 1 and 15: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
       Grayscale_conversion();
        break;
    case 2:
        BW();
        break;
    case 3:
        invert();
        break;
    case 4:
        merge();
        break;
    case 5:
        flip();
        break;
    case 6:
        rotate_90();
        break;
    case 7:
        darken_lighten();
        break;
    case 8:
        crop_image_filter();
        break;
    case 9:
        simple_frame();
        break;
    case 10:
        edge();
        break; 
    case 11:
        resize_image_filter();
        break;
    case 12:
        Blur_filter();
        break;
    case 13:
        sunlight();
        break;
    case 14:
        purple_filter();
        break;
    case 15:
        infrared();
        break;

    default:
    cout << "Exiting the program...\n";
        exit(0);
    }

    
    
}



int main() {

   
   while(true)menu();


   return 0;
}
