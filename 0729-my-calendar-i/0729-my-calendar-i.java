class MyCalendar {
    HashMap<Integer, Integer> mp = new HashMap<>();
    public MyCalendar() {
        
    }
    
    public boolean book(int start, int end) {
        for(int first:mp.keySet()) {
            int second = mp.get(first);
            if(Math.max(first, start) < Math.min(second, end)) return false;
        }
        mp.put(start, end);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */