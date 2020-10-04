require(lme4)
require(lmerTest) 
require(EMAtools)
require(MuMIn)
require(Hmisc)
require(Rmisc)
require(ggpubr)


# for RC=0.4, MS=20
data_RC04_LTM20 <- read.csv("./Agent10/RC04LTM20G5000/AllinOne.csv")
data_RC04_LTM20$Run <- factor(data_RC04_LTM20$Run)
data_RC04_LTM20$Time <- factor(data_RC04_LTM20$Time)
data_RC04_LTM20$Nature <- factor(data_RC04_LTM20$Nature)
data_RC04_LTM20$Culture <- factor(data_RC04_LTM20$Culture)
data_RC04_LTM20$UR <- data_RC04_LTM20$UR/64.0

fitUR <- lmer(UR ~ Nature * Culture + (1|Time) + (1|Run), data=data_RC04_LTM20)
summary(fitUR)
# REML criterion at convergence: -4967.1
# 
# Scaled residuals: 
#   Min      1Q  Median      3Q     Max 
# -3.5693 -0.5719 -0.0764  0.7341  4.1023 
# 
# Random effects:
#   Groups   Name        Variance Std.Dev.
# Time     (Intercept) 0.02620  0.16187 
# Run      (Intercept) 0.00111  0.03332 
# Residual             0.04438  0.21066 
# Number of obs: 20200, groups:  Time, 101; Run, 50
# 
# Fixed effects:
#   Estimate Std. Error         df t value Pr(>|t|)    
# (Intercept)       2.130e-02  1.704e-02  1.211e+02   1.250    0.214    
# Nature1           6.947e-01  4.192e-03  2.005e+04 165.697  < 2e-16 ***
#   Culture1         -6.612e-05  4.192e-03  2.005e+04  -0.016    0.987    
# Nature1:Culture1  2.860e-02  5.929e-03  2.005e+04   4.824 1.42e-06 ***
#   ---
#   Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
# 
# Correlation of Fixed Effects:
#   (Intr) Natur1 Cultr1
# Nature1     -0.123              
# Culture1    -0.123  0.500       
# Natr1:Cltr1  0.087 -0.707 -0.707

lme.dscore(fitUR, data_RC04_LTM20, 'lme4')
#                             t    df             d
# Nature1          165.69721215 20047  2.3405639051
# Culture1          -0.01577182 20047 -0.0002227855
# Nature1:Culture1   4.82372615 20047  0.0681377747

fitRC <- lmer(RC ~ Nature * Culture + (1|Time) + (1|Run), data=data_RC04_LTM20)
summary(fitRC)
# REML criterion at convergence: -1765.7
# 
# Scaled residuals: 
#   Min      1Q  Median      3Q     Max 
# -3.5224 -0.6136  0.1147  0.6060  3.1534 
# 
# Random effects:
#   Groups   Name        Variance Std.Dev.
# Time     (Intercept) 0.005684 0.07539 
# Run      (Intercept) 0.004682 0.06843 
# Residual             0.052275 0.22864 
# Number of obs: 20200, groups:  Time, 101; Run, 50
# 
# Fixed effects:
#   Estimate Std. Error         df t value Pr(>|t|)    
# (Intercept)       4.821e-01  1.266e-02  1.149e+02   38.08  < 2e-16 ***
#   Nature1           3.517e-01  4.550e-03  2.005e+04   77.30  < 2e-16 ***
#   Culture1         -3.686e-02  4.550e-03  2.005e+04   -8.10  5.8e-16 ***
#   Nature1:Culture1  8.933e-02  6.435e-03  2.005e+04   13.88  < 2e-16 ***
#   ---
#   Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
# 
# Correlation of Fixed Effects:
#   (Intr) Natur1 Cultr1
# Nature1     -0.180              
# Culture1    -0.180  0.500       
# Natr1:Cltr1  0.127 -0.707 -0.707

lme.dscore(fitRC, data_RC04_LTM20, 'lme4')
#                          t    df          d
# Nature1          77.303159 20047  1.0919495
# Culture1         -8.100221 20047 -0.1144201
# Nature1:Culture1 13.883104 20047  0.1961065


fitLTM <- lmer(LTM ~ Nature * Culture + (1|Time) + (1|Run), data=data_RC04_LTM20)
summary(fitLTM)
# REML criterion at convergence: 125711.1
# 
# Scaled residuals: 
#   Min      1Q  Median      3Q     Max 
# -3.8082 -0.5840  0.0275  0.5979  5.7397 
# 
# Random effects:
#   Groups   Name        Variance Std.Dev.
# Time     (Intercept)  0.8008  0.8949  
# Run      (Intercept)  6.7540  2.5988  
# Residual             28.9230  5.3780  
# Number of obs: 20200, groups:  Time, 101; Run, 50
# 
# Fixed effects:
#   Estimate Std. Error         df t value Pr(>|t|)    
# (Intercept)         19.7160     0.3857    58.0343  51.123  < 2e-16 ***
#   Nature1             10.6263     0.1070 20047.0001  99.287  < 2e-16 ***
#   Culture1            -0.3250     0.1070 20047.0001  -3.037   0.0024 ** 
#   Nature1:Culture1    -0.9809     0.1514 20047.0001  -6.481 9.33e-11 ***
#   ---
#   Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
# 
# Correlation of Fixed Effects:
#   (Intr) Natur1 Cultr1
# Nature1     -0.139              
# Culture1    -0.139  0.500       
# Natr1:Cltr1  0.098 -0.707 -0.707

lme.dscore(fitLTM, data_RC04_LTM20, 'lme4')
# t    df           d
# Nature1          99.286745 20047  1.40247966
# Culture1         -3.036543 20047 -0.04289283
# Nature1:Culture1 -6.480860 20047 -0.09154570


fitMaxLTM <- lmer(MaxLTM ~ Nature * Culture + (1|Time) + (1|Run), data=data_RC04_LTM20)
summary(fitMaxLTM)
# REML criterion at convergence: 128449.7
# 
# Scaled residuals: 
#   Min      1Q  Median      3Q     Max 
# -3.7266 -0.6043  0.0465  0.6376  5.1948 
# 
# Random effects:
#   Groups   Name        Variance Std.Dev.
# Time     (Intercept)  2.626   1.620   
# Run      (Intercept)  7.907   2.812   
# Residual             32.965   5.742   
# Number of obs: 20200, groups:  Time, 101; Run, 50
# 
# Fixed effects:
#   Estimate Std. Error         df t value Pr(>|t|)    
# (Intercept)         19.8823     0.4367    68.7730  45.533  < 2e-16 ***
#   Nature1             14.0811     0.1143 20047.0000 123.237  < 2e-16 ***
#   Culture1            -0.3793     0.1143 20047.0000  -3.319 0.000903 ***
#   Nature1:Culture1    -1.6571     0.1616 20047.0000 -10.255  < 2e-16 ***
#   ---
#   Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
# 
# Correlation of Fixed Effects:
#   (Intr) Natur1 Cultr1
# Nature1     -0.131              
# Culture1    -0.131  0.500       
# Natr1:Cltr1  0.093 -0.707 -0.707

lme.dscore(fitMaxLTM, data_RC04_LTM20, 'lme4')
# t    df           d
# Nature1          123.236625 20047  1.74078484
# Culture1          -3.319478 20047 -0.04688945
# Nature1:Culture1 -10.255295 20047 -0.14486166


rcorr(as.matrix(data_RC04_LTM20[, c("UR", "RC", "LTM", "MaxLTM")]))
# UR   RC  LTM MaxLTM
# UR     1.00 0.66 0.60   0.73
# RC     0.66 1.00 0.42   0.49
# LTM    0.60 0.42 1.00   0.97
# MaxLTM 0.73 0.49 0.97   1.00



# for RC=0.7, MS=50
data_RC07_LTM50 <- read.csv("./Agent10/RC07LTM50G5000/AllinOne.csv")
data_RC07_LTM50$Run <- factor(data_RC07_LTM50$Run)
data_RC07_LTM50$Time <- factor(data_RC07_LTM50$Time)
data_RC07_LTM50$Nature <- factor(data_RC07_LTM50$Nature)
data_RC07_LTM50$Culture <- factor(data_RC07_LTM50$Culture)
data_RC07_LTM50$UR <- data_RC07_LTM50$UR/64.0

fitUR <- lmer(UR ~ Nature * Culture + (1|Time) + (1|Run), data=data_RC07_LTM50)
summary(fitUR)
# REML criterion at convergence: 8484
# 
# Scaled residuals: 
#   Min      1Q  Median      3Q     Max 
# -2.5125 -0.8158  0.1163  0.6671  2.5410 
# 
# Random effects:
#   Groups   Name        Variance Std.Dev.
# Time     (Intercept) 0.009198 0.09591 
# Run      (Intercept) 0.004409 0.06640 
# Residual             0.086964 0.29490 
# Number of obs: 20200, groups:  Time, 101; Run, 50
# 
# Fixed effects:
#   Estimate Std. Error         df t value Pr(>|t|)    
# (Intercept)       4.702e-01  1.402e-02  1.454e+02  33.544  < 2e-16 ***
#   Nature1           4.172e-01  5.869e-03  2.005e+04  71.095  < 2e-16 ***
#   Culture1          4.233e-02  5.869e-03  2.005e+04   7.214 5.64e-13 ***
#   Nature1:Culture1 -3.848e-02  8.300e-03  2.005e+04  -4.636 3.58e-06 ***
#   ---
#   Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
# 
# Correlation of Fixed Effects:
#   (Intr) Natur1 Cultr1
# Nature1     -0.209              
# Culture1    -0.209  0.500       
# Natr1:Cltr1  0.148 -0.707 -0.707     

lme.dscore(fitUR, data_RC07_LTM50, 'lme4')
# t    df          d
# Nature1          71.095162 20047  1.0042581
# Culture1          7.213682 20047  0.1018972
# Nature1:Culture1 -4.635948 20047 -0.0654853


fitRC <- lmer(RC ~ Nature * Culture + (1|Time) + (1|Run), data=data_RC07_LTM50)
summary(fitRC)
# REML criterion at convergence: -3914.5
# 
# Scaled residuals: 
#   Min       1Q   Median       3Q      Max 
# -2.91799 -0.53268 -0.02111  0.58411  2.72568 
# 
# Random effects:
#   Groups   Name        Variance  Std.Dev.
# Time     (Intercept) 0.0009866 0.03141 
# Run      (Intercept) 0.0041984 0.06480 
# Residual             0.0473460 0.21759 
# Number of obs: 20200, groups:  Time, 101; Run, 50
# 
# Fixed effects:
#   Estimate Std. Error         df t value Pr(>|t|)    
# (Intercept)       5.236e-01  1.015e-02  6.926e+01  51.566   <2e-16 ***
#   Nature1           1.887e-01  4.330e-03  2.005e+04  43.577   <2e-16 ***
#   Culture1         -3.720e-03  4.330e-03  2.005e+04  -0.859    0.390    
# Nature1:Culture1  2.294e-03  6.124e-03  2.005e+04   0.375    0.708    
# ---
#   Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
# 
# Correlation of Fixed Effects:
#   (Intr) Natur1 Cultr1
# Nature1     -0.213              
# Culture1    -0.213  0.500       
# Natr1:Cltr1  0.151 -0.707 -0.707

lme.dscore(fitRC, data_RC07_LTM50, 'lme4')
# t    df            d
# Nature1          43.5770199 20047  0.615549280
# Culture1         -0.8590772 20047 -0.012134937
# Nature1:Culture1  0.3746420 20047  0.005292023 


fitLTM <- lmer(LTM ~ Nature * Culture + (1|Time) + (1|Run), data=data_RC07_LTM50)
summary(fitLTM)
# REML criterion at convergence: 127324.8
# 
# Scaled residuals: 
#   Min      1Q  Median      3Q     Max 
# -4.4851 -0.6033 -0.1037  0.4324  5.1480 
# 
# Random effects:
#   Groups   Name        Variance Std.Dev.
# Time     (Intercept)  1.603   1.266   
# Run      (Intercept)  2.271   1.507   
# Residual             31.332   5.597   
# Number of obs: 20200, groups:  Time, 101; Run, 50
# 
# Fixed effects:
#   Estimate Std. Error         df t value Pr(>|t|)    
# (Intercept)         39.8302     0.2598    94.7830 153.311  < 2e-16 ***
#   Nature1             -4.1888     0.1114 20046.9999 -37.603  < 2e-16 ***
#   Culture1            -0.5316     0.1114 20046.9999  -4.772 1.83e-06 ***
#   Nature1:Culture1     0.4489     0.1575 20046.9999   2.849  0.00439 ** 
#   ---
#   Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
# 
# Correlation of Fixed Effects:
#   (Intr) Natur1 Cultr1
# Nature1     -0.214              
# Culture1    -0.214  0.500       
# Natr1:Cltr1  0.152 -0.707 -0.707

lme.dscore(fitLTM, data_RC07_LTM50, 'lme4')
# t    df           d
# Nature1          -37.603135 20047 -0.53116489
# Culture1          -4.772453 20047 -0.06741352
# Nature1:Culture1   2.849339 20047  0.04024848


fitMaxLTM <- lmer(MaxLTM ~ Nature * Culture + (1|Time) + (1|Run), data=data_RC07_LTM50)
summary(fitMaxLTM)
# REML criterion at convergence: 130891.3
# 
# Scaled residuals: 
#   Min      1Q  Median      3Q     Max 
# -5.1597 -0.4655 -0.0315  0.5107  4.4379 
# 
# Random effects:
#   Groups   Name        Variance Std.Dev.
# Time     (Intercept)  0.5104  0.7144  
# Run      (Intercept)  6.5595  2.5612  
# Residual             37.5103  6.1246  
# Number of obs: 20200, groups:  Time, 101; Run, 50
# 
# Fixed effects:
#   Estimate Std. Error         df t value Pr(>|t|)    
# (Intercept)         46.6832     0.3790    57.0625 123.162   <2e-16 ***
#   Nature1              3.3884     0.1219 20046.9997  27.800   <2e-16 ***
#   Culture1             0.2944     0.1219 20046.9997   2.416   0.0157 *  
#   Nature1:Culture1    -0.1905     0.1724 20046.9997  -1.105   0.2692    
# ---
#   Signif. codes:  0 '***' 0.001 '**' 0.01 '*' 0.05 '.' 0.1 ' ' 1
# 
# Correlation of Fixed Effects:
#   (Intr) Natur1 Cultr1
# Nature1     -0.161              
# Culture1    -0.161  0.500       
# Natr1:Cltr1  0.114 -0.707 -0.707

lme.dscore(fitMaxLTM, data_RC07_LTM50, 'lme4')
# t    df           d
# Nature1          27.800320 20047  0.39269475
# Culture1          2.415554 20047  0.03412103
# Nature1:Culture1 -1.104928 20047 -0.01560771


rcorr(as.matrix(data_RC07_LTM50[, c("UR", "RC", "LTM", "MaxLTM")]))
# UR    RC   LTM MaxLTM
# UR      1.00  0.76 -0.53   0.35
# RC      0.76  1.00 -0.57   0.12
# LTM    -0.53 -0.57  1.00   0.41
# MaxLTM  0.35  0.12  0.41   1.00



# get data and draw figures
geom.text.size = 8; theme.size = 3*geom.text.size

savefig <- function(fileName, dpi, width, height, units, type){
  #' Function to save figures
  #' @param fileName file name of the figure
  #' @param dpi resolution, e.g., 300
  #' @param width figure width in inches (units)
  #' @param height figure height in inches (units)
  #' @param units unit name for width and height, e.g., 'in'
  #' @param type figure type: 'png', png figure; 'pdf', pdf figure; 'both', both png and pdf figures
  
  if(type=="png"){ file <- paste(fileName, ".png", sep=""); ggsave(file, dpi = dpi, width = width, height = height, units = units) }
  if(type=="pdf"){ file <- paste(fileName, ".pdf", sep=""); ggsave(file, dpi = dpi, width = width, height = height, units = units) }
  if(type=="both"){
    file <- paste(fileName, ".png", sep=""); ggsave(file, dpi = dpi, width = width, height = height, units = units)
    file <- paste(fileName, ".pdf", sep=""); ggsave(file, dpi = dpi, width = width, height = height, units = units)
  }
}


# draw each condition
drawEachCond <- function(data, nat, cul, cond, resdir){
  # get subdata
  subdata <- data[(data$Nature==nat)&(data$Culture==cul),]
  xticks <- seq(0,5000,by=1000)
  
  # for UR
  # calculate average results across runs
  group.mean <- summarySE(subdata, measurevar="UR", groupvars=c("Time"), na.rm=TRUE)
  names(group.mean)[3] <- 'X'
  title <- paste(cond, ': UR', sep=""); ylab <- 'UR'
  # draw figure
  URfig <- ggplot(group.mean, aes(x=Time, y=X)) + 
    geom_errorbar(aes(ymin=X-se, ymax=X+se), width=2) +
    geom_line(aes(group=1), color='red', size=2) + 
    ylim(c(0,1)) + ylab(ylab) + 
    scale_x_discrete(name ="Generation", breaks=xticks, labels=xticks) + 
    ggtitle(title) +???
    theme(plot.title=element_text(size=theme.size), axis.title=element_text(size=theme.size, face="bold"), 
          axis.text.x=element_text(angle=0, hjust=0.5, size=theme.size), axis.text.y=element_text(size=theme.size),
          panel.grid.major=element_line(colour="grey", linetype="dotted", size=1))
  savefig(paste(resdir, '\\', cond, "_UR", sep=""), 300, 10, 8, "in", "both")
  
  # for RC
  # calculate average results across runs
  group.mean <- summarySE(subdata, measurevar="RC", groupvars=c("Time"), na.rm=TRUE)
  names(group.mean)[3] <- 'X'
  title <- paste(cond, ': RC', sep=""); ylab <- 'RC'
  # draw figure
  RCfig <- ggplot(group.mean, aes(x=Time, y=X)) + 
    geom_errorbar(aes(ymin=X-se, ymax=X+se), width=2) +
    geom_line(aes(group=1), color='blue', size=2) + 
    ylim(c(0.35,1)) + ylab(ylab) + 
    scale_x_discrete(name ="Generation", breaks=xticks, labels=xticks) + 
    ggtitle(title) +???
    theme(plot.title=element_text(size=theme.size), axis.title=element_text(size=theme.size, face="bold"), 
          axis.text.x=element_text(angle=0, hjust=0.5, size=theme.size), axis.text.y=element_text(size=theme.size),
          panel.grid.major=element_line(colour="grey", linetype="dotted", size=1))
  savefig(paste(resdir, '\\', cond, "_RC", sep=""), 300, 10, 8, "in", "both")
  
  # for LTM
  # calculate average results across runs
  group.mean <- summarySE(subdata, measurevar="LTM", groupvars=c("Time"), na.rm=TRUE)
  names(group.mean)[3] <- 'X'
  title <- paste(cond, ': LTM', sep=""); ylab <- 'LTM'
  # draw figure
  LTMfig <- ggplot(group.mean, aes(x=Time, y=X)) + 
    geom_errorbar(aes(ymin=X-se, ymax=X+se), width=2) +
    geom_line(aes(group=1), color='pink', size=2) + 
    ylim(c(15,55)) + ylab(ylab) + 
    scale_x_discrete(name ="Generation", breaks=xticks, labels=xticks) + 
    ggtitle(title) +???
    theme(plot.title=element_text(size=theme.size), axis.title=element_text(size=theme.size, face="bold"), 
          axis.text.x=element_text(angle=0, hjust=0.5, size=theme.size), axis.text.y=element_text(size=theme.size),
          panel.grid.major=element_line(colour="grey", linetype="dotted", size=1))
  savefig(paste(resdir, '\\', cond, "_LTM", sep=""), 300, 10, 8, "in", "both")
  
  # for MaxLTM
  # calculate average results across runs
  group.mean <- summarySE(subdata, measurevar="MaxLTM", groupvars=c("Time"), na.rm=TRUE)
  names(group.mean)[3] <- 'X'
  title <- paste(cond, ': MS', sep=""); ylab <- 'MS'
  # draw figure
  MaxLTMfig <- ggplot(group.mean, aes(x=Time, y=X)) + 
    geom_errorbar(aes(ymin=X-se, ymax=X+se), width=2) +
    geom_line(aes(group=1), color='green', size=2) + 
    ylim(c(15,55)) + ylab(ylab) + 
    scale_x_discrete(name ="Generation", breaks=xticks, labels=xticks) + 
    ggtitle(title) +???
    theme(plot.title=element_text(size=theme.size), axis.title=element_text(size=theme.size, face="bold"), 
          axis.text.x=element_text(angle=0, hjust=0.5, size=theme.size), axis.text.y=element_text(size=theme.size),
          panel.grid.major=element_line(colour="grey", linetype="dotted", size=1))
  savefig(paste(resdir, '\\', cond, "_MS", sep=""), 300, 10, 8, "in", "both")
  
  # combine URfig, RCfig and MaxLTMfig
  ggarrange(URfig, RCfig, MaxLTMfig,
            ncol = 1, nrow = 3)
  savefig(paste(resdir, '\\', cond, "_ALL", sep=""), 300, 10, 16, "in", "both")
}

# draw UR, RC, and MaxLTM across 4 conditions
condSet <- data.frame(nat = c(0,0,1,1), cul = c(0,1,0,1), cond = c('NoNat_NoCul', 'NoNat_Cul', 'Nat_NoCul', 'Nat_Cul'))

resdir <- "./Agent10/RC04LTM20G5000"
data <- data_RC04_LTM20
for(i in 1:4){
  drawEachCond(data, condSet$nat[i], condSet$cul[i], condSet$cond[i], resdir)
}
resdir <- "./Agent10/RC07LTM50G5000"
data <- data_RC07_LTM50
for(i in 1:4){
  drawEachCond(data, condSet$nat[i], condSet$cul[i], condSet$cond[i], resdir)
}



# require(xlsx)
# drawRes <- function(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2){
#   # get data
#   NoNat_NoCul <- read.xlsx(file, sheetName = SheetNameList[1], header=FALSE, startRow = startRow, endRow = endRow); names(NoNat_NoCul) <- c("Mean", "Std")
#   NoNat_Cul <- read.xlsx(file, sheetName = SheetNameList[2], header=FALSE, startRow = startRow, endRow = endRow); names(NoNat_Cul) <- c("Mean", "Std")
#   Nat_NoCul <- read.xlsx(file, sheetName = SheetNameList[3], header=FALSE, startRow = startRow, endRow = endRow); names(Nat_NoCul) <- c("Mean", "Std")
#   Nat_Cul <- read.xlsx(file, sheetName = SheetNameList[4], header=FALSE, startRow = startRow, endRow = endRow); names(Nat_Cul) <- c("Mean", "Std")
#   NoNat <- (NoNat_NoCul + NoNat_Cul)/2.0; NoNat$Condition <- "NoNat"; NoNat <- cbind(time, NoNat)
#   Nat <- (Nat_NoCul + Nat_Cul)/2.0; Nat$Condition <- "Nat"; Nat <- cbind(time, Nat)
#   DF1 <- rbind(NoNat, Nat); if(type=="UR"){ DF1$Mean <- DF1$Mean/64.0; DF1$Std <- DF1$Std/64.0; }
#   NoCul <- (NoNat_NoCul + Nat_NoCul)/2.0; NoCul$Condition <- "NoCul"; NoCul <- cbind(time, NoCul)
#   Cul <- (NoNat_Cul + Nat_Cul)/2.0; Cul$Condition <- "Cul"; Cul <- cbind(time, Cul)
#   DF2 <- rbind(NoCul, Cul); if(type=="UR"){ DF2$Mean <- DF2$Mean/64.0; DF2$Std <- DF2$Std/64.0; }
#   # draw figure
#   ggplot(DF1, aes(x=Time, y=Mean, linetype=Condition)) + 
#     geom_line() + 
#     geom_errorbar(aes(ymin=Mean-Std/sqrt(numRun), ymax=Mean+Std/sqrt(numRun)), width=.5, position=position_dodge(.9)) + 
#     ggtitle(titles[1]) + xlab(xlabs[1]) + ylab(ylabs[1]) + xlim(xlim) + ylim(ylim) + 
#     theme_bw() + 
#     theme(plot.title=element_text(size=theme.size), axis.title=element_text(size=theme.size, face="bold"), 
#           axis.text.x=element_text(angle=0, hjust=0.5, size=theme.size), axis.text.y=element_text(size=theme.size),
#           panel.grid.major=element_line(colour="grey", linetype="dotted", size=1))
#   ggsave(FigName1, dpi = 300, width = 6, height = 4, units = "in")
#   ggplot(DF2, aes(x=Time, y=Mean, linetype=Condition)) + 
#     geom_line() + 
#     geom_errorbar(aes(ymin=Mean-Std/sqrt(numRun), ymax=Mean+Std/sqrt(numRun)), width=.5, position=position_dodge(.9)) + 
#     ggtitle(titles[2]) + xlab(xlabs[2]) + ylab(ylabs[2]) + xlim(xlim) + ylim(ylim) +  
#     theme_bw() + 
#     theme(plot.title=element_text(size=theme.size), axis.title=element_text(size=theme.size, face="bold"), 
#           axis.text.x=element_text(angle=0, hjust=0.5, size=theme.size), axis.text.y=element_text(size=theme.size),
#           panel.grid.major=element_line(colour="grey", linetype="dotted", size=1))
#   ggsave(FigName2, dpi = 300, width = 6, height = 4, units = "in")
# }
# 
# sheetsEnding <- c("avg_std_NoNat_NoCul", "avg_std_NoNat_Cul", "avg_std_Nat_NoCul", "avg_std_Nat_Cul")
# numRun <- 50
# startRow <- 1; endRow <- 101
# 
# # RC 0.4 and LTM 20
# direct <- file.path("Agent10", "RC04LTM20G10000"); fileName <- "UR_RC_LTM_MaxLTM.xls"; file <- file.path(direct, fileName)
# time <- read.xlsx(file, sheetName = "Time", header=FALSE, startRow = startRow, endRow = endRow); names(time) <- "Time"
# 
# # for UR
# type <- "UR"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("UR (Understanding Rate) under Nat", "UR (Understanding Rate) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean UR", "Mean UR")
# xlim <- c(0,5000); ylim <- c(0, 1.0)
# FigName1 <- file.path(direct, "UR_nat.png"); FigName2 <- file.path(direct, "UR_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# # for RC
# type <- "RC"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("RC (Reliability of Cue) under Nat", "RC (Reliability of Cue) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean RC", "Mean RC")
# xlim <- c(0,5000); ylim <- c(0.3, 1.0)
# FigName1 <- file.path(direct, "RC_nat.png"); FigName2 <- file.path(direct, "RC_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# # for LTM
# type <- "LTM"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("MS (Memory Size) under Nat", "MS (Memory Size) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean MS", "Mean MS")
# xlim <- c(0,5000); ylim <- c(15, 45)
# FigName1 <- file.path(direct, "MS_nat.png"); FigName2 <- file.path(direct, "MS_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# # for MaxLTM
# type <- "MaxLTM"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("MS (Memory Size) under Nat", "MS (Memory Size) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean MS", "Mean MS")
# xlim <- c(0,5000); ylim <- c(15, 45)
# FigName1 <- file.path(direct, "MaxMS_nat.png"); FigName2 <- file.path(direct, "MaxMS_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# 
# # RC 0.7 and LTM 50
# direct <- file.path("Agent10", "RC07LTM50G10000"); fileName <- "UR_RC_LTM_MaxLTM.xls"; file <- file.path(direct, fileName)
# time <- read.xlsx(file, sheetName = "Time", header=FALSE, startRow = startRow, endRow = endRow); names(time) <- "Time"
# 
# # for UR
# type <- "UR"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("UR (Understanding Rate) under Nat", "UR (Understanding Rate) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean UR", "Mean UR")
# xlim <- c(0,5000); ylim <- c(0, 1.0)
# FigName1 <- file.path(direct, "UR_nat.png"); FigName2 <- file.path(direct, "UR_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# # for RC
# type <- "RC"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("RC (Reliability of Cue) under Nat", "RC (Reliability of Cue) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean RC", "Mean RC")
# xlim <- c(0,5000); ylim <- c(0.3, 1.0)
# FigName1 <- file.path(direct, "RC_nat.png"); FigName2 <- file.path(direct, "RC_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# # for LTM
# type <- "LTM"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("MS (Memory Size) under Nat", "MS (Memory Size) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean LTM", "Mean LTM")
# xlim <- c(0,5000); ylim <- c(15, 50)
# FigName1 <- file.path(direct, "MS_nat.png"); FigName2 <- file.path(direct, "MS_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# # for MaxLTM
# type <- "MaxLTM"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("MS (Memory Size) under Nat", "MS (Memory Size) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean MS", "Mean MS")
# xlim <- c(0,5000); ylim <- c(40, 55)
# FigName1 <- file.path(direct, "MaxMS_nat.png"); FigName2 <- file.path(direct, "MaxMS_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# 
# # Rc0.2, LTM20 100 agents
# direct <- file.path("Agent100", "RC04LTM20G5000"); fileName <- "UR_RC_LTM_MaxLTM.xls"; file <- file.path(direct, fileName)
# time <- read.xlsx(file, sheetName = "Time", header=FALSE, startRow = startRow, endRow = endRow); names(time) <- "Time"
# 
# # for UR
# type <- "UR"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("UR (Understanding Rate) under Nat", "UR (Understanding Rate) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean UR", "Mean UR")
# xlim <- c(0,5000); ylim <- c(0, 1.0)
# FigName1 <- file.path(direct, "UR_nat.png"); FigName2 <- file.path(direct, "UR_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# # for RC
# type <- "RC"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("RC (Reliability of Cue) under Nat", "RC (Reliability of Cue) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean RC", "Mean RC")
# xlim <- c(0,5000); ylim <- c(0.35, 1.0)
# FigName1 <- file.path(direct, "RC_nat.png"); FigName2 <- file.path(direct, "RC_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# # for LTM
# type <- "LTM"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("MS (Memory Size) under Nat", "MS (Memory Size) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean LTM", "Mean LTM")
# xlim <- c(0,5000); ylim <- c(15, 45)
# FigName1 <- file.path(direct, "MS_nat.png"); FigName2 <- file.path(direct, "MS_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
# 
# # for MaxLTM
# type <- "MaxLTM"; SheetNameList <- paste(type, sheetsEnding, sep="_")
# titles <- c("MS (Memory Size) under Nat", "MS (Memory Size) under Cul")
# xlabs <- c("No. Generations", "No. Generations"); ylabs <- c("Mean MS", "Mean MS")
# xlim <- c(0,5000); ylim <- c(15, 45)
# FigName1 <- file.path(direct, "MaxMS_nat.png"); FigName2 <- file.path(direct, "MaxMS_cul.png")
# drawRes(type, numRun, startRow, endRow, SheetNameList, file, time, titles, xlabs, ylabs, xlim, ylim, FigName1, FigName2)
