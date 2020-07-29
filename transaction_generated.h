// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TRANSACTION_SCHEDULER_H_
#define FLATBUFFERS_GENERATED_TRANSACTION_SCHEDULER_H_

#include "flatbuffers/flatbuffers.h"

namespace Scheduler {

struct MetaCommand;
struct MetaCommandBuilder;

struct MetaResult;
struct MetaResultBuilder;

struct Read;
struct ReadBuilder;

struct ReadResult;
struct ReadResultBuilder;

struct Write;
struct WriteBuilder;

struct WriteStatus;
struct WriteStatusBuilder;

enum Action {
  Action_Start = 0,
  Action_Commit = 1,
  Action_MIN = Action_Start,
  Action_MAX = Action_Commit
};

inline const Action (&EnumValuesAction())[2] {
  static const Action values[] = {
    Action_Start,
    Action_Commit
  };
  return values;
}

inline const char * const *EnumNamesAction() {
  static const char * const names[3] = {
    "Start",
    "Commit",
    nullptr
  };
  return names;
}

inline const char *EnumNameAction(Action e) {
  if (flatbuffers::IsOutRange(e, Action_Start, Action_Commit)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesAction()[index];
}

struct MetaCommand FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef MetaCommandBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ACTION = 4
  };
  Scheduler::Action action() const {
    return static_cast<Scheduler::Action>(GetField<int8_t>(VT_ACTION, 0));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_ACTION) &&
           verifier.EndTable();
  }
};

struct MetaCommandBuilder {
  typedef MetaCommand Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_action(Scheduler::Action action) {
    fbb_.AddElement<int8_t>(MetaCommand::VT_ACTION, static_cast<int8_t>(action), 0);
  }
  explicit MetaCommandBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<MetaCommand> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<MetaCommand>(end);
    return o;
  }
};

inline flatbuffers::Offset<MetaCommand> CreateMetaCommand(
    flatbuffers::FlatBufferBuilder &_fbb,
    Scheduler::Action action = Scheduler::Action_Start) {
  MetaCommandBuilder builder_(_fbb);
  builder_.add_action(action);
  return builder_.Finish();
}

struct MetaResult FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef MetaResultBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_STATUS = 4,
    VT_TRANSACTION = 6
  };
  bool status() const {
    return GetField<uint8_t>(VT_STATUS, 0) != 0;
  }
  int32_t transaction() const {
    return GetField<int32_t>(VT_TRANSACTION, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_STATUS) &&
           VerifyField<int32_t>(verifier, VT_TRANSACTION) &&
           verifier.EndTable();
  }
};

struct MetaResultBuilder {
  typedef MetaResult Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_status(bool status) {
    fbb_.AddElement<uint8_t>(MetaResult::VT_STATUS, static_cast<uint8_t>(status), 0);
  }
  void add_transaction(int32_t transaction) {
    fbb_.AddElement<int32_t>(MetaResult::VT_TRANSACTION, transaction, 0);
  }
  explicit MetaResultBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<MetaResult> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<MetaResult>(end);
    return o;
  }
};

inline flatbuffers::Offset<MetaResult> CreateMetaResult(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool status = false,
    int32_t transaction = 0) {
  MetaResultBuilder builder_(_fbb);
  builder_.add_transaction(transaction);
  builder_.add_status(status);
  return builder_.Finish();
}

struct Read FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ReadBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KEY = 4,
    VT_TRANSACTION = 6
  };
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  int32_t transaction() const {
    return GetField<int32_t>(VT_TRANSACTION, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_KEY) &&
           verifier.VerifyString(key()) &&
           VerifyField<int32_t>(verifier, VT_TRANSACTION) &&
           verifier.EndTable();
  }
};

struct ReadBuilder {
  typedef Read Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(Read::VT_KEY, key);
  }
  void add_transaction(int32_t transaction) {
    fbb_.AddElement<int32_t>(Read::VT_TRANSACTION, transaction, 0);
  }
  explicit ReadBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Read> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Read>(end);
    return o;
  }
};

inline flatbuffers::Offset<Read> CreateRead(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    int32_t transaction = 0) {
  ReadBuilder builder_(_fbb);
  builder_.add_transaction(transaction);
  builder_.add_key(key);
  return builder_.Finish();
}

inline flatbuffers::Offset<Read> CreateReadDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    int32_t transaction = 0) {
  auto key__ = key ? _fbb.CreateString(key) : 0;
  return Scheduler::CreateRead(
      _fbb,
      key__,
      transaction);
}

struct ReadResult FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ReadResultBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_STATUS = 4,
    VT_VALUE = 6,
    VT_TRANSACTION = 8
  };
  bool status() const {
    return GetField<uint8_t>(VT_STATUS, 0) != 0;
  }
  const flatbuffers::String *value() const {
    return GetPointer<const flatbuffers::String *>(VT_VALUE);
  }
  int32_t transaction() const {
    return GetField<int32_t>(VT_TRANSACTION, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_STATUS) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyString(value()) &&
           VerifyField<int32_t>(verifier, VT_TRANSACTION) &&
           verifier.EndTable();
  }
};

struct ReadResultBuilder {
  typedef ReadResult Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_status(bool status) {
    fbb_.AddElement<uint8_t>(ReadResult::VT_STATUS, static_cast<uint8_t>(status), 0);
  }
  void add_value(flatbuffers::Offset<flatbuffers::String> value) {
    fbb_.AddOffset(ReadResult::VT_VALUE, value);
  }
  void add_transaction(int32_t transaction) {
    fbb_.AddElement<int32_t>(ReadResult::VT_TRANSACTION, transaction, 0);
  }
  explicit ReadResultBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<ReadResult> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ReadResult>(end);
    return o;
  }
};

inline flatbuffers::Offset<ReadResult> CreateReadResult(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool status = false,
    flatbuffers::Offset<flatbuffers::String> value = 0,
    int32_t transaction = 0) {
  ReadResultBuilder builder_(_fbb);
  builder_.add_transaction(transaction);
  builder_.add_value(value);
  builder_.add_status(status);
  return builder_.Finish();
}

inline flatbuffers::Offset<ReadResult> CreateReadResultDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool status = false,
    const char *value = nullptr,
    int32_t transaction = 0) {
  auto value__ = value ? _fbb.CreateString(value) : 0;
  return Scheduler::CreateReadResult(
      _fbb,
      status,
      value__,
      transaction);
}

struct Write FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef WriteBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KEY = 4,
    VT_VALUE = 6,
    VT_TRANSACTION = 8
  };
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  const flatbuffers::String *value() const {
    return GetPointer<const flatbuffers::String *>(VT_VALUE);
  }
  int32_t transaction() const {
    return GetField<int32_t>(VT_TRANSACTION, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_KEY) &&
           verifier.VerifyString(key()) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyString(value()) &&
           VerifyField<int32_t>(verifier, VT_TRANSACTION) &&
           verifier.EndTable();
  }
};

struct WriteBuilder {
  typedef Write Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(Write::VT_KEY, key);
  }
  void add_value(flatbuffers::Offset<flatbuffers::String> value) {
    fbb_.AddOffset(Write::VT_VALUE, value);
  }
  void add_transaction(int32_t transaction) {
    fbb_.AddElement<int32_t>(Write::VT_TRANSACTION, transaction, 0);
  }
  explicit WriteBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Write> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Write>(end);
    return o;
  }
};

inline flatbuffers::Offset<Write> CreateWrite(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    flatbuffers::Offset<flatbuffers::String> value = 0,
    int32_t transaction = 0) {
  WriteBuilder builder_(_fbb);
  builder_.add_transaction(transaction);
  builder_.add_value(value);
  builder_.add_key(key);
  return builder_.Finish();
}

inline flatbuffers::Offset<Write> CreateWriteDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    const char *value = nullptr,
    int32_t transaction = 0) {
  auto key__ = key ? _fbb.CreateString(key) : 0;
  auto value__ = value ? _fbb.CreateString(value) : 0;
  return Scheduler::CreateWrite(
      _fbb,
      key__,
      value__,
      transaction);
}

struct WriteStatus FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef WriteStatusBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_STATUS = 4,
    VT_TRANSACTION = 6
  };
  bool status() const {
    return GetField<uint8_t>(VT_STATUS, 0) != 0;
  }
  int32_t transaction() const {
    return GetField<int32_t>(VT_TRANSACTION, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_STATUS) &&
           VerifyField<int32_t>(verifier, VT_TRANSACTION) &&
           verifier.EndTable();
  }
};

struct WriteStatusBuilder {
  typedef WriteStatus Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_status(bool status) {
    fbb_.AddElement<uint8_t>(WriteStatus::VT_STATUS, static_cast<uint8_t>(status), 0);
  }
  void add_transaction(int32_t transaction) {
    fbb_.AddElement<int32_t>(WriteStatus::VT_TRANSACTION, transaction, 0);
  }
  explicit WriteStatusBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<WriteStatus> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<WriteStatus>(end);
    return o;
  }
};

inline flatbuffers::Offset<WriteStatus> CreateWriteStatus(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool status = false,
    int32_t transaction = 0) {
  WriteStatusBuilder builder_(_fbb);
  builder_.add_transaction(transaction);
  builder_.add_status(status);
  return builder_.Finish();
}

}  // namespace Scheduler

#endif  // FLATBUFFERS_GENERATED_TRANSACTION_SCHEDULER_H_
