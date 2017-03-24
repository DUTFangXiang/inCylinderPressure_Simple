        if(ftemp > 0.0) // 如果最小值大于零，那么就认为最小值处就开始燃烧
        {
          //如果最大值大于0.1，则说明此时一定存在燃烧过程，但是否存在造成的压力突升，不清楚
            if(fDPDFMax > 0.1 )
            {
                istartposi = iendposi;
                iendposi = istartposi + 560;
                for(int i = istartposi; i< iendposi; i++)
                {
                    fdpdfdf[i - istartposi] = fpDPDF[i+1] - fpDPDF[i];
                }

//----------------------------------------------------------------
// 在调试的时候可以用于判断压力升高率的变化过程
#ifdef  SELF_DEBUG
                FILE *fp;
                AnsiString strTemp;
                strTemp = FormMain->strExeFilePath + "Debug\\dpdfdf.dat";
                if((fp = fopen(strTemp.c_str(), "w")) != NULL)
                {
                    for(int i = istartposi; i < iendposi; i ++)
                    {
                        fprintf( fp, "%d %.5f %.5f\n", i, fpDPDF[i], fdpdfdf[i - istartposi]*300.0);
                    }
                    fclose(fp);
                }
#endif
//===================================================================
                ii1 = iendposi - istartposi;
                bool bEntered = false;
                int izeroNum  = 0;
                ftemp = fdpdfdf[10];
                for(int i = 10; i < ii1 - 10; i ++)
                {
                    if(   ((fdpdfdf[i+1] > 0.0)&&(fdpdfdf[i] < 0.0))
                        ||((fdpdfdf[i+1] < 0.0)&&(fdpdfdf[i] > 0.0))
                      )
                    {
                        izeroNum ++;
                    }
                    if(izeroNum == 2)
                    {
                        bdpdfdfmin       = true;
                        icombustionposi  = i;
                        bCombustionStart = true;
                        bEntered = true;
                        break;
                    }
                }
                if(bEntered)
                {
                    bLowPositive     = true;
                    icombustionposi  += istartposi;
                    bCombustionStart = true;
                    bdpdfdfmin       = true;
                    iendposi         = icombustionposi - 600;
                    if(iendposi < 0)
                    {
                        iendposi = 1;
                    }
                    ftemp = fpDPDF[icombustionposi];
                    iZeroPosi = icombustionposi - 10;
                    for(int i = icombustionposi -10 ; i > iendposi; i --)
                    {
                        if(ftemp < fpDPDF[i])
                        {
                            ftemp     = fpDPDF[i];
                            iZeroPosi = i;
                        }
                    }
                    fdpmax           = fpDPDF[iZeroPosi];
                    fDPDFLocalMax    = fdpmax;
                    bLowPositive     = false;
                }
                else
                {
                    bLowPositive     = true;
                    icombustionposi  += istartposi;
                    bCombustionStart = true;
                    bdpdfdfmin       = true;
                    fdpmax           = fpDPDF[icombustionposi];
                    fDPDFLocalMax    = fdpmax;
                }

            }
            else
            {
                bLowPositive     = true;
                icombustionposi  += istartposi;
                bCombustionStart = true;
                bdpdfdfmin       = true;
                fdpmax           = fpDPDF[icombustionposi];
                fDPDFLocalMax        = fdpmax;
            }
