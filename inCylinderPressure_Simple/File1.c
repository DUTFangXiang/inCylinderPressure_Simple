        if(ftemp > 0.0) // �����Сֵ�����㣬��ô����Ϊ��Сֵ���Ϳ�ʼȼ��
        {
          //������ֵ����0.1����˵����ʱһ������ȼ�չ��̣����Ƿ������ɵ�ѹ��ͻ���������
            if(fDPDFMax > 0.1 )
            {
                istartposi = iendposi;
                iendposi = istartposi + 560;
                for(int i = istartposi; i< iendposi; i++)
                {
                    fdpdfdf[i - istartposi] = fpDPDF[i+1] - fpDPDF[i];
                }

//----------------------------------------------------------------
// �ڵ��Ե�ʱ����������ж�ѹ�������ʵı仯����
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
