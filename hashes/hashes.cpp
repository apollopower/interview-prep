// In C++, hashes are unordered_maps:

unoreded_map<string, int> lightBulbToHoursOfLight;

lightBulbToHoursOfLight.insert(make_pair("incadescent", 1200));
lightBulbToHoursOfLight.insert(make_pair("compact flourescent", 10000));
lightBulbToHoursOfLight.insert(make_pair("LED", 50000));

// We use a hashing function to convert a key (which can be any data type
// that can be hashed) into an array index (which is an integer).

// This is pretty smart and affective

// Be aware of hash collisions (when two different pieces of data get
// hashed into the same result, trying to occupy the same array index
// in memory).

// How to deal with hash collisions?

// Instead of storing the the actual values in an array, store A POINTER
// to a linkedlist holding all the keys that hash to that index.

// If we want to resize our hash table (so make it bigger), allocating a
// larger array and rehashing all of our existing keys to figure out their
// new position—O(n)O(n) time.