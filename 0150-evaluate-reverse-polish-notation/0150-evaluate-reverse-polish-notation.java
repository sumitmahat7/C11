class Solution {
    public int evalRPN(String[] tokens) {
        int[] stack = new int[tokens.length];
        int top = -1; // Pointer to the top of our simulated stack

        for (String s : tokens) {
            switch (s) {
                // For operators, we combine the top two elements and shrink the stack pointer by 1
                case "+" -> { stack[top - 1] += stack[top]; top--; }
                case "-" -> { stack[top - 1] -= stack[top]; top--; }
                case "*" -> { stack[top - 1] *= stack[top]; top--; }
                case "/" -> { stack[top - 1] /= stack[top]; top--; }
                
                // For numbers, we expand the stack pointer and insert the number
                default  -> stack[++top] = Integer.parseInt(s);
            }
        }

        // The final result will be the only item left, sitting at index 0
        return stack[0];
    }
}