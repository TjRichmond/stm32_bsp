// #define SET_BIT(REG,BIT) ((uint32_t)(REG) |= (uint32_t)(BIT))
// #define CLR_BIT(REG,BIT) ((uint32_t)(REG) &= ~(uint32_t)(BIT))

inline __attribute__((always_inline)) void set_bit(uint32_t reg, uint32_t bit) 
{
    reg |= bit;
};

inline __attribute__((always_inline)) void clear_bit(uint32_t reg, uint32_t bit) 
{
    reg &= ~bit;
}