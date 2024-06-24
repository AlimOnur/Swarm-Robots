package com.onur.swarmrobot;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.widget.GridLayout;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
/*
    TextView timeText;

    ImageView imageView0;
    ImageView imageView1;
    ImageView imageView2;
    ImageView imageView3;
    ImageView imageView4;
    ImageView imageView5;
    ImageView imageView6;
    ImageView imageView7;
    ImageView imageView8;
    ImageView imageView9;

    ImageView imageView0_1;
    ImageView imageView1_1;
    ImageView imageView2_1;
    ImageView imageView3_1;
    ImageView imageView4_1;
    ImageView imageView5_1;
    ImageView imageView6_1;
    ImageView imageView7_1;
    ImageView imageView8_1;
    ImageView imageView9_1;

    ImageView imageView0_2;
    ImageView imageView1_2;
    ImageView imageView2_2;
    ImageView imageView3_2;
    ImageView imageView4_2;
    ImageView imageView5_2;
    ImageView imageView6_2;
    ImageView imageView7_2;
    ImageView imageView8_2;
    ImageView imageView9_2;

    ImageView imageView0_3;
    ImageView imageView1_3;
    ImageView imageView2_3;
    ImageView imageView3_3;
    ImageView imageView4_3;
    ImageView imageView5_3;
    ImageView imageView6_3;
    ImageView imageView7_3;
    ImageView imageView8_3;
    ImageView imageView9_3;

    ImageView imageView0_4;
    ImageView imageView1_4;
    ImageView imageView2_4;
    ImageView imageView3_4;
    ImageView imageView4_4;
    ImageView imageView5_4;
    ImageView imageView6_4;
    ImageView imageView7_4;
    ImageView imageView8_4;
    ImageView imageView9_4;

    ImageView imageView0_5;
    ImageView imageView1_5;
    ImageView imageView2_5;
    ImageView imageView3_5;
    ImageView imageView4_5;
    ImageView imageView5_5;
    ImageView imageView6_5;
    ImageView imageView7_5;
    ImageView imageView8_5;
    ImageView imageView9_5;

    ImageView imageView0_6;
    ImageView imageView1_6;
    ImageView imageView2_6;
    ImageView imageView3_6;
    ImageView imageView4_6;
    ImageView imageView5_6;
    ImageView imageView6_6;
    ImageView imageView7_6;
    ImageView imageView8_6;
    ImageView imageView9_6;

    ImageView imageView0_7;
    ImageView imageView1_7;
    ImageView imageView2_7;
    ImageView imageView3_7;
    ImageView imageView4_7;
    ImageView imageView5_7;
    ImageView imageView6_7;
    ImageView imageView7_7;
    ImageView imageView8_7;
    ImageView imageView9_7;

    ImageView imageView0_8;
    ImageView imageView1_8;
    ImageView imageView2_8;
    ImageView imageView3_8;
    ImageView imageView4_8;
    ImageView imageView5_8;
    ImageView imageView6_8;
    ImageView imageView7_8;
    ImageView imageView8_8;
    ImageView imageView9_8;

    ImageView imageView0_9;
    ImageView imageView1_9;
    ImageView imageView2_9;
    ImageView imageView3_9;
    ImageView imageView4_9;
    ImageView imageView5_9;
    ImageView imageView6_9;
    ImageView imageView7_9;
    ImageView imageView8_9;
    ImageView imageView9_9;

    ImageView[] imageArray;




    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        timeText = findViewById(R.id.timeText);

         imageView0 = findViewById(R.id.imageView0);
         imageView1 = findViewById(R.id.imageView1);
         imageView2 = findViewById(R.id.imageView2);
         imageView3 = findViewById(R.id.imageView3);
         imageView4 = findViewById(R.id.imageView4);
         imageView5 = findViewById(R.id.imageView5);
         imageView6 = findViewById(R.id.imageView6);
         imageView7 = findViewById(R.id.imageView7);
         imageView8 = findViewById(R.id.imageView8);
         imageView9 = findViewById(R.id.imageView9);

         imageView0_1= findViewById(R.id.imageView0_1);
         imageView1_1= findViewById(R.id.imageView1_1);
         imageView2_1= findViewById(R.id.imageView2_1);
         imageView3_1= findViewById(R.id.imageView3_1);
         imageView4_1= findViewById(R.id.imageView4_1);
         imageView5_1= findViewById(R.id.imageView5_1);
         imageView6_1= findViewById(R.id.imageView6_1);
         imageView7_1= findViewById(R.id.imageView7_1);
         imageView8_1= findViewById(R.id.imageView8_1);
         imageView9_1= findViewById(R.id.imageView9_1);

         imageView0_2= findViewById(R.id.imageView0_2);
         imageView1_2= findViewById(R.id.imageView1_2);
         imageView2_2= findViewById(R.id.imageView2_2);
         imageView3_2= findViewById(R.id.imageView3_2);
         imageView4_2= findViewById(R.id.imageView4_2);
         imageView5_2= findViewById(R.id.imageView5_2);
         imageView6_2= findViewById(R.id.imageView6_2);
         imageView7_2= findViewById(R.id.imageView7_2);
         imageView8_2= findViewById(R.id.imageView8_2);
         imageView9_2= findViewById(R.id.imageView9_2);

         imageView0_3= findViewById(R.id.imageView0_3);
         imageView1_3= findViewById(R.id.imageView1_3);
         imageView2_3= findViewById(R.id.imageView2_3);
         imageView3_3= findViewById(R.id.imageView3_3);
         imageView4_3= findViewById(R.id.imageView4_3);
         imageView5_3= findViewById(R.id.imageView5_3);
         imageView6_3= findViewById(R.id.imageView6_3);
         imageView7_3= findViewById(R.id.imageView7_3);
         imageView8_3= findViewById(R.id.imageView8_3);
         imageView9_3= findViewById(R.id.imageView9_3);

         imageView0_4= findViewById(R.id.imageView0_4);
         imageView1_4= findViewById(R.id.imageView1_4);
         imageView2_4= findViewById(R.id.imageView2_4);
         imageView3_4= findViewById(R.id.imageView3_4);
         imageView4_4= findViewById(R.id.imageView4_4);
         imageView5_4= findViewById(R.id.imageView5_4);
         imageView6_4= findViewById(R.id.imageView6_4);
         imageView7_4= findViewById(R.id.imageView7_4);
         imageView8_4= findViewById(R.id.imageView8_4);
         imageView9_4= findViewById(R.id.imageView9_4);

         imageView0_5= findViewById(R.id.imageView0_5);
         imageView1_5= findViewById(R.id.imageView1_5);
         imageView2_5= findViewById(R.id.imageView2_5);
         imageView3_5= findViewById(R.id.imageView3_5);
         imageView4_5= findViewById(R.id.imageView4_5);
         imageView5_5= findViewById(R.id.imageView5_5);
         imageView6_5= findViewById(R.id.imageView6_5);
         imageView7_5= findViewById(R.id.imageView7_5);
         imageView8_5= findViewById(R.id.imageView8_5);
         imageView9_5= findViewById(R.id.imageView9_5);

         imageView0_6= findViewById(R.id.imageView0_6);
         imageView1_6= findViewById(R.id.imageView1_6);
         imageView2_6= findViewById(R.id.imageView2_6);
         imageView3_6= findViewById(R.id.imageView3_6);
         imageView4_6= findViewById(R.id.imageView4_6);
         imageView5_6= findViewById(R.id.imageView5_6);
         imageView6_6= findViewById(R.id.imageView6_6);
         imageView7_6= findViewById(R.id.imageView7_6);
         imageView8_6= findViewById(R.id.imageView8_6);
         imageView9_6= findViewById(R.id.imageView9_6);

         imageView0_7= findViewById(R.id.imageView0_7);
         imageView1_7= findViewById(R.id.imageView1_7);
         imageView2_7= findViewById(R.id.imageView2_7);
         imageView3_7= findViewById(R.id.imageView3_7);
         imageView4_7= findViewById(R.id.imageView4_7);
         imageView5_7= findViewById(R.id.imageView5_7);
         imageView6_7= findViewById(R.id.imageView6_7);
         imageView7_7= findViewById(R.id.imageView7_7);
         imageView8_7= findViewById(R.id.imageView8_7);
         imageView9_7= findViewById(R.id.imageView9_7);

         imageView0_8= findViewById(R.id.imageView0_8);
         imageView1_8= findViewById(R.id.imageView1_8);
         imageView2_8= findViewById(R.id.imageView2_8);
         imageView3_8= findViewById(R.id.imageView3_8);
         imageView4_8= findViewById(R.id.imageView4_8);
         imageView5_8= findViewById(R.id.imageView5_8);
         imageView6_8= findViewById(R.id.imageView6_8);
         imageView7_8= findViewById(R.id.imageView7_8);
         imageView8_8= findViewById(R.id.imageView8_8);
         imageView9_8= findViewById(R.id.imageView9_8);

         imageView0_9= findViewById(R.id.imageView0_9);
         imageView1_9= findViewById(R.id.imageView1_9);
         imageView2_9= findViewById(R.id.imageView2_9);
         imageView3_9= findViewById(R.id.imageView3_9);
         imageView4_9= findViewById(R.id.imageView4_9);
         imageView5_9= findViewById(R.id.imageView5_9);
         imageView6_9= findViewById(R.id.imageView6_9);
         imageView7_9= findViewById(R.id.imageView7_9);
         imageView8_9= findViewById(R.id.imageView8_9);
         imageView9_9= findViewById(R.id.imageView9_9);



        GridLayout.LayoutParams params = (GridLayout.LayoutParams) imageView0.getLayoutParams();

        GridLayout.Spec row = params.rowSpec;
        GridLayout.Spec column = params.columnSpec;

// Row ve column değerlerini konsola yazdıralım
        System.out.println("Row: " + row + ", Column: " + column);




         imageArray = new ImageView[]  {imageView0, imageView1, imageView2, imageView3, imageView4, imageView5, imageView6, imageView7, imageView8, imageView9,
                                        imageView0_1, imageView1_1, imageView2_1, imageView3_1, imageView4_1, imageView5_1, imageView6_1, imageView7_1, imageView8_1, imageView9_1,
                                        imageView0_2, imageView1_2, imageView2_2, imageView3_2, imageView4_2, imageView5_2, imageView6_2, imageView7_2, imageView8_2, imageView9_2,
                                        imageView0_3, imageView1_3, imageView2_3, imageView3_3, imageView4_3, imageView5_3, imageView6_3, imageView7_3, imageView8_3, imageView9_3,
                                        imageView0_4, imageView1_4, imageView2_4, imageView3_4, imageView4_4, imageView5_4, imageView6_4, imageView7_4, imageView8_4, imageView9_4,
                                        imageView0_5, imageView1_5, imageView2_5, imageView3_5, imageView4_5, imageView5_5, imageView6_5, imageView7_5, imageView8_5, imageView9_5,
                                        imageView0_6, imageView1_6, imageView2_6, imageView3_6, imageView4_6, imageView5_6, imageView6_6, imageView7_6, imageView8_6, imageView9_6,
                                        imageView0_7, imageView1_7, imageView2_7, imageView3_7, imageView4_7, imageView5_7, imageView6_7, imageView7_7, imageView8_7, imageView9_7,
                                        imageView0_8, imageView1_8, imageView2_8, imageView3_8, imageView4_8, imageView5_8, imageView6_8, imageView7_8, imageView8_8, imageView9_8,
                                        imageView0_9, imageView1_9, imageView2_9, imageView3_9, imageView4_9, imageView5_9, imageView6_9, imageView7_9, imageView8_9, imageView9_9
         };



*/



    }




















