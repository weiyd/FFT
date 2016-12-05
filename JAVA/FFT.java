package com.milink.android.air.fftpack;

public class FFT{

    // 无参构造函数（软件模拟输入信号）
    public FFT() {
        N=256;
        M=(int) (Math.log(N)/Math.log(2));
        data = new complex[N];
        for(int i=0;i<N;i++)
            data[i]=new complex();
        InputData();

        // 生成正弦表
        SIN_TABLE = new double[N];
        for (int i = 0; i < N; ++i) {
            SIN_TABLE[i] = Math.sin(2 * PI * i / N);
        }
    }

    // 带参构造函数
    public FFT(double[] Data) {
        N=Data.length;
        M=(int) (Math.log(N)/Math.log(2));

        //外部传入数据
        double sum=0;
        data = new complex[N];
        for(int i=0;i<N;i++)
            sum+=Data[i];
        sum/=N;
        for(int i=0;i<N;i++)
        {
            data[i] = new complex();
            data[i].real=Data[i]-sum;
        }

        // 生成正弦表
        SIN_TABLE = new double[N];
        for (int i = 0; i < N; ++i) {
            SIN_TABLE[i] = Math.sin(2 * PI * i / N);
        }
    }

    //查询正弦波
    private double Sin_find(double x) {
        int i = (int) (N * x);
        i = i >> 1;
        if (i > N / 4)
            i = N / 2 - i;
        return SIN_TABLE[i];
    }

    // 查询余弦波
    private double Cos_find(double x) {
        int i = (int) (N * x);
        i = i >> 1;
        if (i < N / 4)
            return SIN_TABLE[N / 4 - i];
        else
            return -SIN_TABLE[i - N / 4];
    }

    // 软件模拟数据
    private void InputData() {
        for (int i = 0; i < N; i++) {
            double t = i * 1.0 / N;
            data[i].real = 2 + 3 * Math.cos(2 * PI * 50 * t - PI * 30 / 180)
                    + 1.5 * Math.cos(2 * PI * 75 * t + PI * 90 / 180);
            data[i].image = 0;
        }
    }

    //雷德算法变址
    private void ChangeSeat(complex[] DataInput){
        int nextValue, nextM, i, k, j = 0;
        complex temp;
        nextValue = N / 2;                  //变址运算，即把自然顺序变成倒位序，采用雷德算法
        nextM = N - 1;
        for (i = 0; i < nextM; i++)
        {
            if (i < j)					//如果i<j,即进行变址
            {
                temp = DataInput[j];
                DataInput[j] = DataInput[i];
                DataInput[i] = temp;
            }
            k = nextValue;                //求j的下一个倒位序
            while (k <= j)				//如果k<=j,表示j的最高位为1
            {
                j = j - k;					//把最高位变成0
                k = k / 2;					//k/2，比较次高位，依次类推，逐个比较，直到某个位为0
            }
            j = j + k;						//把0改为1
        }
    }

    // FFT计算
    public void StartFFT(){
        int L = 0, B = 0, J = 0, K = 0;
        int step = 0, KB = 0;
        //ElemType P=0;
        double angle;
        complex W, Temp_XX;
        W=new complex();
        Temp_XX=new complex();

        ChangeSeat(data);//变址
        for (L = 1; L <= M; L++)
        {
            step = 1 << L;//2^L
            B = step >> 1;//B=2^(L-1)
            for (J = 0; J < B; J++)
            {
                //P = (1<<(M-L))*J;//P=2^(M-L) *J
                angle = (double)J / B;
                W.image = -Sin_find(angle);
                W.real = Cos_find(angle);
                for (K = J; K < N; K = K + step)
                {
                    KB = K + B;
                    Temp_XX.real = data[KB].real * W.real - data[KB].image*W.image;
                    Temp_XX.image = W.image*data[KB].real + data[KB].image*W.real;

                    data[KB].real = data[K].real - Temp_XX.real;
                    data[KB].image = data[K].image - Temp_XX.image;

                    data[K].real = data[K].real + Temp_XX.real;
                    data[K].image = data[K].image + Temp_XX.image;
                }
            }
        }
    }

    // 计算频谱幅值
    public double[] FFT_RESULT() {
        double Result[]=new double[N];
        for(int i=0;i<N;i++)
        {
            Result[i]=Math.sqrt(data[i].real * data[i].real
                    + data[i].image * data[i].image);
        }
        return Result;

    }

    // 圆周率
    private static final double PI = 3.14159265358979323846264338327950288419716939937510;
    // 傅里叶变换点数
    private int N ;
    // 蝶形运算级数
    private int M ;
    // 原始数据与输出结果
    private complex data[]=null;
    // SIN_TABLE
    private double SIN_TABLE[]=null;
}