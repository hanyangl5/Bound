module;
import types;

export module blob;

export namespace bd {

struct blob {
  public:
    inline void set(void *data, uint64 size) {
        m_data = data;
        m_size = size;
    }
    inline void *data() const { return m_data; }
    inline uint64 size() const { return m_size; }
    inline void release() {
        
    }
    inline void reset() {
        m_data = nullptr;
        m_size = 0;
    }

  private:
    void *m_data = nullptr;
    uint64 m_size = 0;
};
} // namespace bd