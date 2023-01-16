package gnu.mapping;

import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectOutput;
import java.io.ObjectStreamException;

/* loaded from: classes.dex */
public class SimpleSymbol extends Symbol {
    public SimpleSymbol() {
    }

    public SimpleSymbol(String key) {
        super(Namespace.EmptyNamespace, key);
    }

    @Override // gnu.mapping.Symbol, java.io.Externalizable
    public void writeExternal(ObjectOutput out) throws IOException {
        out.writeObject(getName());
    }

    @Override // gnu.mapping.Symbol, java.io.Externalizable
    public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
        this.name = ((String) in.readObject()).intern();
    }

    @Override // gnu.mapping.Symbol
    public Object readResolve() throws ObjectStreamException {
        return Namespace.EmptyNamespace.getSymbol(getName().intern());
    }
}