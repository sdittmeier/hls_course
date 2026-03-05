# Fix Initiation Interval Mismatches

In this tutorial, we will examine a simple HLS kernel that demonstrates initiation interval mismatches. The goal is to identify and fix these mismatches to achieve optimal performance.

## 1. Task Instructions

### 1.1 Create the Vitis HLS Component

### 1.2 Run C-synthesis and Analyze Reports
1. Run C-synthesis on the kernel
2. Examine the synthesis report
3. Look for initiation interval mismatches in the pipeline directives
4. What is the cause of this mismatch?

### 1.3 Fix the Initiation Interval Mismatches
1. Modify the code to resolve conflicts
2. Ensure all loops can achieve their target initiation intervals of II=1
3. Re-run C-synthesis to verify the fix
4. Compare reports to confirm the fix worked

## 2. Expected Outcome

After fixing the initiation interval mismatches, you should see that all pipeline directives achieve their target II=1, and thus improved performance.
How does it change the resource estimates?