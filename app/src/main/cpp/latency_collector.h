#ifndef ALVRCLIENT_LATENCY_COLLECTOR_H
#define ALVRCLIENT_LATENCY_COLLECTOR_H
#include <jni.h>
#include <memory>

class LatencyCollector {
public:
    LatencyCollector(JNIEnv *env, jobject latencyCollector);

    void recordEstimatedSent(JNIEnv *env, uint64_t frameIndex, uint64_t estimetedSentTime);
    void recordFirstPacketReceived(JNIEnv *env, uint64_t frameIndex);
    void recordLastPacketReceived(JNIEnv *env, uint64_t frameIndex);
    void recordPacketLoss(JNIEnv *env, int64_t lost);
    void recordFecFailure(JNIEnv *env);

    uint64_t getLatency(JNIEnv *env, uint32_t i, uint32_t j);

    uint64_t getPacketsLostTotal(JNIEnv *env);
    uint64_t getPacketsLostInSecond(JNIEnv *env);
    uint64_t getFecFailureTotal(JNIEnv *env);
    uint64_t getFecFailureInSecond(JNIEnv *env);

    void resetAll(JNIEnv *env);
private:
    jobject latencyCollector_;
    jclass latencyCollectorClass_;
    jmethodID latencyCollectorEstimatedSent_;
    jmethodID latencyCollectorReceivedFirst_;
    jmethodID latencyCollectorReceivedLast_;
    jmethodID latencyCollectorPacketLoss_;
    jmethodID latencyCollectorFecFailure_;
    jmethodID latencyCollectorGetLatency_;
    jmethodID latencyCollectorGetPacketsLostTotal_;
    jmethodID latencyCollectorGetPacketsLostInSecond_;
    jmethodID latencyCollectorGetFecFailureTotal_;
    jmethodID latencyCollectorGetFecFailureInSecond_;
    jmethodID latencyCollectorResetAll_;
};

extern std::shared_ptr<LatencyCollector> g_latencyCollector;

#endif //ALVRCLIENT_LATENCY_COLLECTOR_H
